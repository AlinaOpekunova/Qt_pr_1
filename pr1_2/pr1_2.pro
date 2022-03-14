QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    eighthtask.cpp \
    fifthtask.cpp \
    fourthtask.cpp \
    logoperation.cpp \
    main.cpp \
    mainwindow.cpp \
    ninthtask.cpp \
    secondtask.cpp \
    seventhtask.cpp \
    thirdtask.cpp

HEADERS += \
    Itor.h \
    NewList.h \
    eighthtask.h \
    fifthtask.h \
    fourthtask.h \
    logoperation.h \
    mainwindow.h \
    myList.h \
    myVector.h \
    ninthtask.h \
    secondtask.h \
    seventhtask.h \
    thirdtask.h

FORMS += \
    eighthtask.ui \
    fifthtask.ui \
    fourthtask.ui \
    mainwindow.ui \
    ninthtask.ui \
    secondtask.ui \
    seventhtask.ui \
    thirdtask.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
