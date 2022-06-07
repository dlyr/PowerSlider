cmake_minimum_required(VERSION 3.12)

project(PowerSliderDemo)

find_package(PowerSlider REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(demo_source
    main.cpp
 )
    
add_executable(${PROJECT_NAME}  ${demo_source})
target_link_libraries(${PROJECT_NAME} PowerSlider::PowerSlider )
