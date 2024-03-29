#-------------------------------------------------
#
# Project created by QtCreator 2019-07-20T20:59:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ServiceFeedbackSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature ThankYouof Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        Utility/StorageFileOperation.cpp \
        View/AllReviewView.cpp \
        main.cpp \
        View/ServiceFeedback.cpp \
        Log/Log.cpp \
        View/ThankYou.cpp

HEADERS += \
        Utility/DataType/FileDatatype.h \
        Utility/StorageFileOperation.h \
        View/AllReviewView.h \
        View/ServiceFeedback.h \
        Log/Log.h \
        View/ThankYou.h

FORMS += \
        UI/reviewview.ui \
        UI/servicefeedback.ui \
        UI/thankyou.ui

RESOURCES += \
        Resources/ThankYou.gif

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
