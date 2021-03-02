cmake_minimum_required(VERSION 3.12)

project(PowerSlider)

option(BUILD_DESIGNER_PLUNGIN "Build Qt Designer Plugin" ON)
option(BUILD_EXAMPLE_APP "Build example app" ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Xml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(BUNDLE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bundle-${CMAKE_CXX_COMPILER_ID})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/bin)
set(EXECUTABLE_OUTPUT_PATH         ${BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/lib)

set(lib_SOURCES
    ./src/PowerSlider.cpp
    )

add_library(PowerSlider SHARED ${lib_SOURCES} )
target_link_libraries(PowerSlider Qt5::Xml Qt5::Widgets )

if(BUILD_DESIGNER_PLUNGIN)
    target_compile_definitions(PowerSlider PRIVATE "POWERSLIDER_DESIGNER_PLUGIN")
endif()

install(TARGETS PowerSlider DESTINATION lib)
install(DIRECTORY src/ DESTINATION include/PowerSlider
    FILES_MATCHING PATTERN "*.hpp")


if(BUILD_DESIGNER_PLUNGIN)
    find_package(Qt5 REQUIRED COMPONENTS Core Widgets Xml)
    set(plugin_SOURCES
        ./src/PowerSlider.cpp 
        ./src/PowerSliderPlugin.cpp
        )
    
    add_library(PowerSliderPlugin SHARED  ${plugin_SOURCES})
    target_link_libraries(PowerSliderPlugin Qt5::UiTools Qt5::Xml Qt5::Widgets )
    
    install(TARGETS PowerSliderPlugin DESTINATION plugins/designer)
endif(BUILD_DESIGNER_PLUNGIN)

if(BUILD_EXAMPLE_APP)
    set(example_SOURCES
        ./example/main.cpp
        ./src/PowerSlider.cpp)
    
    add_executable(example  ${example_SOURCES})
    target_link_libraries(example Qt5::Xml Qt5::Widgets )
    target_include_directories(example PUBLIC  ${CMAKE_SOURCE_DIR})
endif(BUILD_EXAMPLE_APP)
