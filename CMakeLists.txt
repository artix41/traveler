#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)


project(myproject)

include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "myproject")

add_definitions(-std=c++11 -Wall -O3) #pedantic  -g...

# add_executable(${EXECUTABLE_NAME} main.cpp)
file(
        GLOB_RECURSE
        source_files
        src/*
)

add_executable(
        ${EXECUTABLE_NAME}
        ${source_files}
)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
