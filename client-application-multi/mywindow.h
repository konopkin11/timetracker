#ifndef MYWINDOW_H
#define MYWINDOW_H


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QCloseEvent>
#include <QVBoxLayout>
#include <QEvent>
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
    void changeEvent(QEvent* event) override {
        if (event->type() == QEvent::ActivationChange) {
          if (!isActiveWindow()) {
            this->hide();
            //this->closeEvent(new QCloseEvent);
          }
        }
      }
};

#endif // MYWINDOW_H
