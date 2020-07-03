QT       += core gui

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
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    alterlinux-i3-manager_ja_JP.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pic/polybar-none.png \
    pic/polybar-round.png \
    pic/polybar-sharp.png \
    pic/polybar-sharprev.png \
    polybar/blocks/blocks_none.ini \
    polybar/blocks/blocks_round.ini \
    polybar/blocks/blocks_sharp.ini \
    polybar/blocks/blocks_sharprev.ini \
    polybar/colors/colors_clear_dark.ini \
    polybar/colors/colors_clear_light.ini \
    polybar/colors/colors_unclear_dark.ini \
    polybar/colors/colors_unclear_light.ini \
    polybar/colors/icons/icons_colorful_dark.ini \
    polybar/colors/icons/icons_colorful_light.ini \
    polybar/colors/icons/icons_simple_dark.ini \
    polybar/colors/icons/icons_simple_light.ini \
    polybar/config.ini \
    polybar/launch.sh \
    polybar/modules.ini \
    polybar/setting
