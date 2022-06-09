
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
