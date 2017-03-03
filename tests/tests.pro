QT += network

CONFIG += c++11

SOURCES += main.cpp                       \
           Staple_Test.cpp                \
           StaplesApplication_Test.cpp    \
           StaplesNetworkFactory_Test.cpp

INCLUDEPATH += ../inc/ \
               ../src/

INCLUDEPATH += /usr/include/
LIBS += -lgtest -L/usr/lib/ -lgcov

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# HEADERS += ../inc/Staple.h
