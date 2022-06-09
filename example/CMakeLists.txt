cmake_minimum_required(VERSION 3.12)

project(PowerSliderDemo)

include(../cmake/findQtPackage.cmake)
find_qt_package(COMPONENTS Core Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(PowerSlider REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(PowerSliderDemo  main.cpp)
target_link_libraries(PowerSliderDemo PowerSlider::PowerSlider )
set_target_properties(PowerSliderDemo PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
