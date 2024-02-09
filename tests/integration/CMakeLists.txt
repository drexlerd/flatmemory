cmake_minimum_required(VERSION 3.21)


##############################################################
# Language setup
##############################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


##############################################################
# Establish project
##############################################################

project(integration_example VERSION "0.0.1" LANGUAGES C CXX)


##############################################################
# CMake modules and macro files
##############################################################

find_package(flatmemory COMPONENTS parsers REQUIRED PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
if(flatmemory_FOUND)
  include_directories(${flatmemory_INCLUDE_DIRS})
  message(STATUS "Found flatmemory: ${flatmemory_DIR} (found version ${flatmemory_VERSION})")
endif()
message("${flatmemory_INCLUDE_DIRS}")


##############################################################
# Add library and executable targets
##############################################################

add_executable(integration_standalone "main.cpp")
