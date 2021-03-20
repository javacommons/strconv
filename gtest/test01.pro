QT -= gui

CONFIG += c++20 console

SOURCES += \
        test01.cpp

INCLUDEPATH += $$PWD/..

LIBS +=  -lgtest_main -lgtest
