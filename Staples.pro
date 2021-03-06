QT += qml network quick svg

CONFIG += c++11

SOURCES += src/main.cpp \
           src/Staple.cpp \
           src/StaplesApplication.cpp \
           src/StaplesManager.cpp \
           src/StaplesObjFactory.cpp \
           src/StaplesModel.cpp

RESOURCES += rcs/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

INCLUDEPATH += inc/

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += inc/Staple.h \
    inc/StaplesApplication.h \
    inc/StaplesManager.h \
    inc/StaplesObjFactory.h \
    inc/StaplesModel.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    rcs/main.qml \
    qml/Characteristics.qml \
    qml/Dialog.qml \
    qml/Label.qml \
    qml/main.qml \
    qml/Menu.qml \
    qml/Services.qml \
    README.md

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
