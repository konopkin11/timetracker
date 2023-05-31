#include "myapplication.h"
#include "myapplication.h"
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include "mywindow.h"
#include <QtConcurrent>
#include "macosAppleScript.cpp"
MyApplication::MyApplication(int &argc, char **argv) : QApplication(argc, argv) {

    window = new MyWindow();

    QAction *openAction = new QAction("Open", this);
   connect(openAction, &QAction::triggered, window, &QWidget::show);
   QAction *exitAction = new QAction("Exit", this);
   connect(exitAction, &QAction::triggered, this, &QApplication::quit);


   QMenu *trayIconMenu = new QMenu();
   trayIconMenu->addAction(openAction);
   trayIconMenu->addAction(exitAction);
   QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
   trayIcon->setContextMenu(trayIconMenu);
   trayIcon->setIcon(QIcon("/Users/evgenijkonopkin/work/invisibles/timetracker/client-application-multi/hrhe.png"));  // set icon for your application
   trayIcon->show();

   connect(&watcher, &QFutureWatcher<std::tuple<QString, QString, QString>>::finished, this, &MyApplication::updateWindowInfo);
   // Start the first update.
   QFuture<std::tuple<QString, QString, QString>> future = QtConcurrent::run(getActiveWindowAndApp);
   watcher.setFuture(future);
}
void MyApplication::updateWindowInfo() {
    if (watcher.isFinished()) {
        std::tuple<QString, QString, QString> result = watcher.result();

        QString appName = std::get<0>(result);
        QString windowName = std::get<1>(result);
        QString url = std::get<2>(result);

        // Update your widget here with the new information.
               QString info = QString("App Name: %1\nWindow Name: %2\nURL: %3")
                              .arg(appName)
                              .arg(windowName)
                              .arg(url);
               window->setLabelText(info);

        // Schedule the next update.
        QFuture<std::tuple<QString, QString, QString>> future = QtConcurrent::run(getActiveWindowAndApp);
        watcher.setFuture(future);
    }
}
