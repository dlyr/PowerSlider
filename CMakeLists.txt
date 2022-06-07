cmake_minimum_required(VERSION 3.12)

project(PowerSlider)

option(BUILD_DESIGNER_PLUGIN "Build Qt Designer Plugin" ON)
option(BUILD_EXAMPLE_APP "Build example app" ON)

#
# Qt5 and Qt6 can be retrieved using versionless targets introduced in Qt5.15:
# https://doc.qt.io/qt-6/cmake-qt5-and-qt6-compatibility.html#versionless-targets
macro(find_qt_package)
    set(options REQUIRED)
    set(oneValueArgs "")
    set(multiValueArgs COMPONENTS)

    cmake_parse_arguments(MY_OPTIONS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT MY_OPTIONS_COMPONENTS) # User didn't enter any component
        set(MY_OPTIONS_COMPONENTS "")
    endif()

    find_package(Qt6 COMPONENTS ${MY_OPTIONS_COMPONENTS} QUIET)
    if(NOT Qt6_FOUND)
        if(${MY_OPTIONS_REQUIRED})
            find_package(Qt5 5.15 COMPONENTS ${MY_OPTIONS_COMPONENTS} REQUIRED)
        else()
            find_package(Qt5 5.15 COMPONENTS ${MY_OPTIONS_COMPONENTS})
        endif()
    endif()
endmacro()

find_qt_package(COMPONENTS Core Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(BUNDLE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Bundle-${CMAKE_CXX_COMPILER_ID}-${CMAKE_BUILD_TYPE}")
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX
        "${BUNDLE_DIRECTORY}"
        CACHE PATH "Install path prefix, prepended onto install directories." FORCE
        )
    message("Set install prefix to ${CMAKE_INSTALL_PREFIX}")
endif()
include(GNUInstallDirs)

set(lib_SOURCES
    ./src/PowerSlider.cpp
    )

add_library(PowerSlider SHARED ${lib_SOURCES} )
target_link_libraries(PowerSlider Qt::Widgets )

if(BUILD_DESIGNER_PLUNGIN)
    target_compile_definitions(PowerSlider PRIVATE "POWERSLIDER_DESIGNER_PLUGIN")
endif()

install(TARGETS PowerSlider DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/PowerSlider
    FILES_MATCHING PATTERN "*.hpp")


if(BUILD_DESIGNER_PLUNGIN)
    find_qt_package( COMPONENTS Core Widgets UiTools REQUIRED)
    set(plugin_SOURCES
        ./src/PowerSlider.cpp 
        ./src/PowerSliderPlugin.cpp
        )
    
    add_library(PowerSliderPlugin SHARED  ${plugin_SOURCES})
    target_link_libraries(PowerSliderPlugin Qt::UiTools Qt::Widgets )
    
    install(TARGETS PowerSliderPlugin DESTINATION plugins/designer)
endif(BUILD_DESIGNER_PLUNGIN)

if(BUILD_EXAMPLE_APP)
    set(example_SOURCES
        ./example/main.cpp
        ./src/PowerSlider.cpp)
    
    add_executable(example  ${example_SOURCES})
    target_link_libraries(example Qt::Widgets )
    target_include_directories(example PUBLIC  ${CMAKE_SOURCE_DIR})
endif(BUILD_EXAMPLE_APP)
