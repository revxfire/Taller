#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T10:46:42
#
#-------------------------------------------------

QT       += core gui sql multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taller
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Modelos/mclientes.cpp \
    Modelos/mconexion.cpp \
    Funciones/fclientes.cpp \
    Presentacion/frmclientes.cpp \
    Presentacion/frmreparacion.cpp \
    Presentacion/frmagenda.cpp \
    Presentacion/frmcamara.cpp

    Modelos/clsconexion.cpp

HEADERS  += mainwindow.h \
    Modelos/mclientes.h \
    Modelos/mconexion.h \
    Funciones/fclientes.h \
    Presentacion/frmclientes.h \
    Presentacion/frmreparacion.h \
    Presentacion/frmagenda.h \
    Presentacion/frmcamara.h

    Modelos/clsconexion.h

FORMS    += mainwindow.ui \
    Presentacion/frmclientes.ui \
    Presentacion/frmreparacion.ui \
    Presentacion/frmagenda.ui \
    Presentacion/frmcamara.ui

RESOURCES += \
    iconos.qrc

QMAKE_CXXFLAGS += -std=c++0x
