cmake_minimum_required(VERSION 3.13.4)

project("CPP_CMAKE")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Set the cmake modules path to find the cmake Find* files
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)

# Set the source and library file paths
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Set this to the Maya version you have installed as it will use this version code to 
# determine file paths in the FindMaya.cmake script
set(MAYA_VERSION 2022 CACHE STRING "Maya version")
set(MAYA_INCLUDE_DIR "C:/Program Files/Autodesk/Maya${MAYA_VERSION}/include")

# Glob together all the source code / GLSL files
file(GLOB_RECURSE SOURCE_FILES
    ${SRC_DIR}/*.h
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.vert
    ${SRC_DIR}/*.frag
)

# Use the modules/FindMaya.cmake finder
find_package(Maya REQUIRED)

# Link MLL Plugin File
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Maya::Maya)
MAYA_PLUGIN(${PROJECT_NAME})
