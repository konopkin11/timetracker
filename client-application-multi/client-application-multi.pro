QT       += core gui
QT += concurrent
QMAKE_INFO_PLIST = Info.plist
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#LIBS += -framework ApplicationServices

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    linuxScript.cpp \
    macosAppleScript.cpp \
    main.cpp \
    myapplication.cpp \
    windowsScript.cpp

HEADERS += \
    myapplication.h \
    mywindow.h

FORMS += \
    mainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    hrhe.png

