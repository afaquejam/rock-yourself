TARGET = RockYourself-GUI
TEMPLATE = app

target.path = /usr/bin

shortcutfiles.files += .resource/RockYourself.desktop
shortcutfiles.files += Icons/desktop.png
shortcutfiles.path = /usr/share/applications

data.files += .resource/rock-music
data.files += .resource/rock-video
data.path = /usr/bin

INSTALLS += target
INSTALLS += shortcutfiles
INSTALLS += data

SOURCES += \
    main.cpp \
    rockbrains.cpp \
    rockprocess.cpp

HEADERS += \
    rockbrains.h \
    rockprocess.h

RESOURCES += \
    Icons.qrc
