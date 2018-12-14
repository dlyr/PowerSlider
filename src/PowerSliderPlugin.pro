TEMPLATE    = lib
CONFIG      += designer plugin debug_and_release debug_and_release_target

CONFIG(debug,debug|release) {
	DESTDIR = plugin/debug
}

CONFIG(release,debug|release) {
	DESTDIR = plugin/release
}

CONFIG(debug, debug|release) {
    unix: TARGET = $$join(TARGET,,,_debug)
    else: TARGET = $$join(TARGET,,d)
}

HEADERS     = PowerSlider.h \
              PowerSliderPlugin.h
SOURCES     = PowerSlider.cpp \
              PowerSliderPlugin.cpp

# install
target.path = ~/.qt/plugins/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path =  ~/.qt/plugins/designer/PowerSliderPlugin
INSTALLS += target sources
