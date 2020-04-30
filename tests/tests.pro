include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall #-Wextra -Werror
QMAKE_CFLAGS += -Wall #-Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


SOURCES += \
#../app/editor.cpp \
../app/load.cpp \
../app/move.cpp \
../app/plb.cpp \
../app/s1.cpp \
../app/save.cpp \
../app/show.cpp \
../app/showclassified.cpp \
../app/text/get_line.cpp \
../app/text/append_line.cpp \
../app/text/move1.cpp \
../app/text/s.cpp \
../app/text/process_forward.cpp \
../app/text/remove_all.cpp \
../app/text/show_all.cpp

DISTFILES += \
input.txt \
D:\Programs\test_second_lab\build-qmake-gtest-Desktop_Qt_5_14_1_MinGW_64_bit-Debug\app\in

HEADERS += \
../app/common.h \
../app/text/_text.h \
../app/text/text.h \
    move_test.h \
    plb_test.h \
    save_test.h \
    split_test.h

DEFINES += INPUTDIRSAVE=\\\"$$PWD/testsave\\\" \
    INPUTDIRPLB=\\\"$$PWD/testplb\\\" \
    INPUTDIRMOVE=\\\"$$PWD/testmove\\\" \
    INPUTDIRSPLIT=\\\"$$PWD/testsplit\\\" \
    INPUTDIRCLASS=\\\"$$PWD/testshowclassified\\\"




SOURCES +=     main.cpp \
    ../app/myfunc.c

INCLUDEPATH += ../app
