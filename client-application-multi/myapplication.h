#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H


#include <QApplication>
#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>
#include "mywindow.h"

class MyApplication : public QApplication {
    Q_OBJECT
public:
    MyApplication(int &argc, char **argv);
private:
    MyWindow *window;
private slots:
    void updateWindowInfo();

private:
    QFutureWatcher<std::tuple<QString, QString, QString>> watcher;

};



#endif // MYAPPLICATION_H
