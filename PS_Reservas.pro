QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aeropuerto.cpp \
    reserva.cpp \
    logincontroller.cpp \
    buscarreservaview.cpp \
    cancelarreservaview.cpp \
    connector.cpp \
    destino.cpp \
    detallesreservaview.cpp \
    empleado.cpp \
    listarreservasview.cpp \
    maestroempleadosview.cpp \
    maestrovuelosview.cpp \
    main.cpp \
    loginview.cpp \
    mainview.cpp \
    nuevareservadview.cpp \
    nuevareservauview.cpp \
    origen.cpp \
    reservascontroller.cpp \
    vuelo.cpp \
    vueloscontroller.cpp

HEADERS += \
    aeropuerto.h \
    reserva.h \
    logincontroller.h \
    buscarreservaview.h \
    cancelarreservaview.h \
    connector.h \
    destino.h \
    detallesreservaview.h \
    empleado.h \
    listarreservasview.h \
    loginview.h \
    maestroempleadosview.h \
    maestrovuelosview.h \
    mainview.h \
    nuevareservadview.h \
    nuevareservauview.h \
    origen.h \
    reservascontroller.h \
    vuelo.h \
    vueloscontroller.h

FORMS += \
    buscarreservaview.ui \
    cancelarreservaview.ui \
    detallesreservaview.ui \
    listarreservasview.ui \
    loginview.ui \
    maestroempleadosview.ui \
    maestrovuelosview.ui \
    mainview.ui \
    nuevareservadview.ui \
    nuevareservauview.ui

TRANSLATIONS += \
    PS_Reservas_es_PE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagen.qrc
