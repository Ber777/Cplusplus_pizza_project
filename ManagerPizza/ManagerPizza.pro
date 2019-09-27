#-------------------------------------------------
#
# Project created by QtCreator 2019-01-08T20:28:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManagerPizza
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ingredient.cpp \
    courier.cpp \
    client.cpp \
    order.cpp \
    payment.cpp \
    pizza.cpp \
    worker.cpp \
    seewindow.cpp \
    addwindow.cpp \
    searchwindow.cpp \
    changewindow.cpp \
    courierservice.cpp \
    datamapper.cpp \
    deletewindow.cpp \
    workerservice.cpp \
    ingredientsservice.cpp \
    pizzaservice.cpp \
    clientservice.cpp \
    orderservice.cpp \
    clientdatamapper.cpp \
    courierdatamapper.cpp \
    workerdatamapper.cpp \
    ingredientdatamapper.cpp \
    pizzadatamapper.cpp \
    orderdatamapper.cpp \
    otchetwindow.cpp

HEADERS += \
        mainwindow.h \
    ingredient.h \
    courier.h \
    client.h \
    order.h \
    payment.h \
    pizza.h \
    worker.h \
    seewindow.h \
    addwindow.h \
    searchwindow.h \
    changewindow.h \
    courierservice.h \
    datamapper.h \
    deletewindow.h \
    workerservice.h \
    ingredientsservice.h \
    pizzaservice.h \
    clientservice.h \
    orderservice.h \
    clientdatamapper.h \
    courierdatamapper.h \
    workerdatamapper.h \
    ingredientdatamapper.h \
    pizzadatamapper.h \
    orderdatamapper.h \
    otchetwindow.h

FORMS += \
        mainwindow.ui \
    seewindow.ui \
    addwindow.ui \
    searchwindow.ui \
    changewindow.ui \
    deletewindow.ui \
    otchetwindow.ui
