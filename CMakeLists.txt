cmake_minimum_required(VERSION 3.24)
project(Current)

set(CMAKE_CXX_STANDARD 17)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#include_directories(include)
#include_directories(src)

set(SOURCE_FILES
	Code/main.cpp
    )

file(GLOB SOURCES
	Code/*.h
	Code/*.cpp
#	include/*.h
#	src/*.cpp
	)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${SOURCES})
