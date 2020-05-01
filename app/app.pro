TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT += core

SOURCES += \
editor.cpp \
load.cpp \
move.cpp \
plb.cpp \
s1.cpp \
save.cpp \
show.cpp \
showclassified.cpp \
text/get_line.cpp \
text/append_line.cpp \
text/move1.cpp \
text/s.cpp \
text/process_forward.cpp \
text/remove_all.cpp \
text/show_all.cpp

DISTFILES += \
input.txt \
D:\Programs\test_second_lab\build-qmake-gtest-Desktop_Qt_5_14_1_MinGW_64_bit-Debug\app\in

HEADERS += \
common.h \
text/_text.h \
text/text.h

RESOURCES += \
    res.qrc
