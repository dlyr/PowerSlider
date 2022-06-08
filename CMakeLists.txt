cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0077 NEW)

project(PowerSlider)

option(BUILD_DESIGNER_PLUGIN "Build Qt Designer Plugin" ON)
option(BUILD_EXAMPLE_APP "Build example app" ON)

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

set(lib_SOURCES
    ./src/PowerSlider.cpp
    )

add_library(${PROJECT_NAME} SHARED ${lib_SOURCES} )
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PRIVATE MAKE_POWERSLIDER)

target_link_libraries(${PROJECT_NAME} Qt::Widgets )
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER src/PowerSlider.hpp)
target_include_directories(
    ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)

if(BUILD_DESIGNER_PLUGIN)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "POWERSLIDER_DESIGNER_PLUGIN")

    find_qt_package( COMPONENTS Core Widgets UiTools REQUIRED)
    set(plugin_SOURCES
        ./src/PowerSlider.cpp 
        ./src/PowerSliderPlugin.cpp
        )
    
    add_library(${PROJECT_NAME}Plugin SHARED  ${plugin_SOURCES})
    target_link_libraries(${PROJECT_NAME}Plugin Qt::UiTools Qt::Widgets )
    target_compile_definitions(${PROJECT_NAME}Plugin PRIVATE MAKE_POWERSLIDER)
endif(BUILD_DESIGNER_PLUGIN)

# manage installation
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# configure the package config file
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake @ONLY
)

# export targets file in buildtree and install targets file and package config file
export(TARGETS ${PROJECT_NAME}
    FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
    )
install(EXPORT ${PROJECT_NAME}Targets NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    )

# install target
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    CONFIGURATIONS ${CMAKE_BUILD_TYPE}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(MSVC OR MSVC_IDE)
        install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION ${CMAKE_INSTALL_BINDIR})
    endif()
endif()

#if(BUILD_DESIGNER_PLUGIN)
#    install(TARGETS ${PROJECT_NAME}Plugin DESTINATION plugins/designer)
#endif(BUILD_DESIGNER_PLUGIN)

# find_package will find PowerSlider package config in the buildtree
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})
set( CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_BINARY_DIR}" PARENT_SCOPE)

# find_package will find PowerSlider package config in the buildtree
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

# manage example
if(BUILD_EXAMPLE_APP)
    add_subdirectory(example)
endif(BUILD_EXAMPLE_APP)
