

TEMPLATE    = lib
SOURCES     = PowerSlider.cpp
HEADERS     = PowerSlider.h
CONFIG *= debug_and_release debug_and_release_target
TARGET  = PowerSlider
VERSION = 0.3
QMAKE_CLEAN *= *~


CONFIG(debug,debug|release) {
	DESTDIR = lib/debug
}

CONFIG(release,debug|release) {
	DESTDIR = lib/release
}
