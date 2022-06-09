cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0077 NEW)

project(PowerSlider)

option(BUILD_DESIGNER_PLUGIN "Build Qt Designer Plugin" ON)
option(BUILD_EXAMPLE_APP "Build example app" ON)

include(cmake/findQtPackage.cmake)
find_qt_package(COMPONENTS Core Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

set(BUNDLE_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/Bundle-${CMAKE_CXX_COMPILER_ID}-${CMAKE_BUILD_TYPE}"
)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX
      "${BUNDLE_DIRECTORY}"
      CACHE PATH "Install path prefix, prepended onto install directories."
            FORCE)
  message("Set install prefix to ${CMAKE_INSTALL_PREFIX}")
endif()

add_library(PowerSlider SHARED ./src/PowerSlider.cpp)

target_compile_definitions(PowerSlider PRIVATE POWERSLIDER_EXPORT)

target_link_libraries(PowerSlider Qt::Widgets)
set_target_properties(PowerSlider PROPERTIES PUBLIC_HEADER src/PowerSlider.hpp)
target_include_directories(
  PowerSlider PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                     $<INSTALL_INTERFACE:include/PowerSlider>)

if(BUILD_DESIGNER_PLUGIN)
  target_compile_definitions(PowerSlider PRIVATE "POWERSLIDER_DESIGNER_PLUGIN")

  find_qt_package(COMPONENTS Core Widgets UiTools REQUIRED)

  add_library(PowerSliderPlugin SHARED ./src/PowerSlider.cpp
                                       ./src/PowerSliderPlugin.cpp)
  target_link_libraries(PowerSliderPlugin Qt::UiTools Qt::Widgets)
  target_compile_definitions(PowerSliderPlugin PRIVATE POWERSLIDER_EXPORT)
endif(BUILD_DESIGNER_PLUGIN)

# manage installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(PowerSlider::PowerSlider ALIAS PowerSlider)

# configure the package config file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
               ${CMAKE_CURRENT_BINARY_DIR}/PowerSliderConfig.cmake @ONLY)

# export targets file in buildtree and install targets file and package config
# file
export(TARGETS PowerSlider
       FILE ${CMAKE_CURRENT_BINARY_DIR}/PowerSliderTargets.cmake)
install(
  EXPORT PowerSliderTargets
  NAMESPACE PowerSlider::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/PowerSlider)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/PowerSliderConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/PowerSlider)

# install target
install(
  TARGETS PowerSlider
  EXPORT PowerSliderTargets
  CONFIGURATIONS ${CMAKE_BUILD_TYPE}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/PowerSlider)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if(MSVC OR MSVC_IDE)
    install(FILES $<TARGET_PDB_FILE:PowerSlider>
            DESTINATION ${CMAKE_INSTALL_BINDIR})
  endif()
endif()

if(BUILD_DESIGNER_PLUGIN)
  install(TARGETS PowerSliderPlugin DESTINATION plugins/designer)
endif(BUILD_DESIGNER_PLUGIN)

# find_package will find PowerSlider package config in the buildtree
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

if(NOT CMAKE_PROJECT_NAME STREQUAL ${PROJECT_NAME})
  set(CMAKE_PREFIX_PATH
      "${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_BINARY_DIR}"
      PARENT_SCOPE)
endif()

# manage example
if(BUILD_EXAMPLE_APP)
  add_subdirectory(example)
endif(BUILD_EXAMPLE_APP)
