QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adchangemyself.cpp \
    adchangepa.cpp \
    addpassenger.cpp \
    addtaxiview.cpp \
    administration.cpp \
    administrationview.cpp \
    changepassengerview.cpp \
    changetaxi.cpp \
    dao.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    middle.cpp \
    nullmessagewarn.cpp \
    passenger.cpp \
    passengerview.cpp \
    person.cpp \
    taxi.cpp \
    taxiview.cpp \
    taxiwork.cpp \
    vehicle.cpp

HEADERS += \
    adchangemyself.h \
    adchangepa.h \
    addpassenger.h \
    addtaxiview.h \
    administration.h \
    administrationview.h \
    changepassengerview.h \
    changetaxi.h \
    dao.h \
    graph.h \
    mainwindow.h \
    middle.h \
    nullmessagewarn.h \
    passenger.h \
    passengerview.h \
    person.h \
    taxi.h \
    taxiview.h \
    taxiwork.h \
    vehicle.h

FORMS += \
    adchangemyself.ui \
    adchangepa.ui \
    addpassenger.ui \
    addtaxiview.ui \
    administrationview.ui \
    changepassengerview.ui \
    changetaxi.ui \
    mainwindow.ui \
    nullmessagewarn.ui \
    passengerview.ui \
    taxiview.ui \
    taxiwork.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
