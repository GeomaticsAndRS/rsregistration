######################################################################
# Automatically generated by qmake (3.0) ?? 3? 12 01:13:02 2013
######################################################################
QT += core gui widgets

TEMPLATE = app
TARGET = new
INCLUDEPATH += .

# Input
HEADERS += imagewindow.h setviewcolorwidget.h ViewWidget.h \
    createraseterpyramids.h \
    InputPointWidget.h \
    OperatDialog.h
FORMS += setViewColor.ui \
    InputPointInf.ui \
    operatDialog.ui
SOURCES += imagewindow.cpp main.cpp setviewcolorwidget.cpp ViewWidget.cpp \
    createraseterpyramids.cpp \
    InputPointWidget.cpp \
    OperatDialog.cpp
RESOURCES += MyIcon.qrc
win32{INCLUDEPATH += C:/OSGeo4W/include \

LIBS += -lC:/OSGeo4W/lib/gdal_i \
}
