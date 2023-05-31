#ifndef MYWINDOW_H
#define MYWINDOW_H


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QCloseEvent>
#include <QVBoxLayout>
class MyWindow : public QWidget {
    Q_OBJECT
public:
    MyWindow() {
        setLayout(new QVBoxLayout());
        label = new QLabel(this);
        layout()->addWidget(label);
    }

    void setLabelText(const QString &text) {
        label->setText(text);
    }
private:
    QLabel *label;
protected:
    void closeEvent(QCloseEvent *event) override {
        this->hide();
        event->ignore();
    }
};

#endif // MYWINDOW_H
