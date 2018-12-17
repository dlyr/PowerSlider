# Distributed under the Apache License, Version 2.0
# see LICENCE file for details.

#.rst:
# FindPowerSlider
# -------
# This package provides necessary information to use PowerSlider.
# PowerSlider is a Qt Widget that join a HorizontalSlider and a DoubleSpinBox
# 



# This will define the following variables::
#
#   PowerSlider_FOUND    - True if the system has the PowerSlider library
#   PowerSlider_VERSION  - The version of the PowerSlider library which was found
#
# and the following imported targets::
#
#   PowerSlider::PowerSlider   - The PowerSlider library
if( NOT PowerSlider_INCLUDE_DIR)
find_path(PowerSlider_INCLUDE_DIR
  NAMES PowerSlider/PowerSlider.hpp
  HINTS
  "${POWER_SLIDER_INSTALL_DIR}/include"
  )
endif()

if( NOT PowerSlider_LIBRARY)
find_library(PowerSlider_LIBRARY
  NAMES PowerSlider
  HINTS
  "${POWER_SLIDER_INSTALL_DIR}/lib"
  )
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PowerSlider
  FOUND_VAR PowerSlider_FOUND
  REQUIRED_VARS
    PowerSlider_LIBRARY
    PowerSlider_INCLUDE_DIR
  VERSION_VAR PowerSlider_VERSION
  )

if(PowerSlider_FOUND)
  set(PowerSlider_LIBRARIES ${PowerSlider_LIBRARY})
  set(PowerSlider_INCLUDE_DIRS ${PowerSlider_INCLUDE_DIR})
  set(PowerSlider_DEFINITIONS ${PowerSlider_CFLAGS_OTHER})
endif()

if(PowerSlider_FOUND AND NOT TARGET PowerSlider::PowerSlider)
  add_library(PowerSlider::PowerSlider UNKNOWN IMPORTED)
  set_target_properties(PowerSlider::PowerSlider PROPERTIES
    IMPORTED_LOCATION "${PowerSlider_LIBRARY}"
    INTERFACE_COMPILE_OPTIONS "${PowerSlider_CFLAGS_OTHER}"
    INTERFACE_INCLUDE_DIRECTORIES "${PowerSlider_INCLUDE_DIR}"
  )
endif()
