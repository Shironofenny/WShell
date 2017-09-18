# Cmake project file
# Yihan Zhang (yz2567@columbia.edu)

project(WShell C)

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

option(BUILD_DEBUG "Turn on the debug mode" OFF)

# ===================================
# Set compiler

if (BUILD_DEBUG)
	add_definitions(-DDEBUG)
	set(CMAKE_BUILD_TYPE Debug)
else ()
	add_definitions(-Wno-deprecated)
	set(CMAKE_BUILD_TYPE Release)
endif ()

# Set output excutable path
set (EXECUTABLE_OUTPUT_PATH ../bin)

# Add header files and source files
file (GLOB WSHELL_HEADERS "./src/*.h")
file (GLOB WSHELL_SOURCES "./src/*.c")

# Compile the excutable
add_executable(wshell ${WSHELL_SOURCES})
#target_link_libraries(wshell ${WSHELL_LIBRARIES})
