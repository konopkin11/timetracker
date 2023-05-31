//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}
#include <QSystemTrayIcon>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QWidget>
#include "myapplication.h"
//#include <ApplicationServices/ApplicationServices.h>

//class MyApplication : public QApplication {
//    Q_OBJECT
//public:
//    MyApplication(int &argc, char **argv) : QApplication(argc, argv) {
//        QWidget *window = new QWidget();

//        QAction *openAction = new QAction("Open", this);
//        connect(openAction, &QAction::triggered, window, &QWidget::show);

//        QMenu *trayIconMenu = new QMenu();
//        trayIconMenu->addAction(openAction);

//        QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
//        trayIcon->setContextMenu(trayIconMenu);
//        trayIcon->setIcon(QIcon("/hrhe.png"));  // set icon for your application
//        trayIcon->show();
//    }
//};

int main(int argc, char **argv) {


    MyApplication app(argc, argv);
    return app.exec();
}
