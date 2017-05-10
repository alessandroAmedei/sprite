#[[cmake_minimum_required(VERSION 3.6)
project(sprite)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(sprite ${SOURCE_FILES})


# Define sources and executable
]]

add_subdirectory(test)

cmake_minimum_required(VERSION 3.4)
set(EXECUTABLE_NAME "sprite")
add_executable(${EXECUTABLE_NAME} main.cpp)
# Detect and add SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

add_library(core B.cpp B.h )
target_link_libraries(${EXECUTABLE_NAME} core)
