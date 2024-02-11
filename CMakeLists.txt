cmake_minimum_required(VERSION 3.21)
project(flatmemory VERSION 0.0.1)


##############################################################
# Language setup
##############################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


##############################################################
# Common Settings
##############################################################

# make cache variables for install destinations
include(GNUInstallDirs)

if(MSVC)
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W1 /EHsc /bigobj /MP")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " /IGNORE:4006,4044,4075")
else()
    # TODO: Add -Wextra and fix all warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -DNDEBUG")
    set(CMAKE_CXX_FLAGS_PROFILING "-O3 -Wall -pg")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g3 -ggdb")
endif()

# set(CMAKE_BUILD_TYPE "Release")

message(STATUS "Build configuration: ${CMAKE_BUILD_TYPE}")


##############################################################
# Add library and executable targets
##############################################################

# -----------
# Target Flatmemory
# -----------
add_subdirectory(src)

# -----------
# Target Test
# -----------
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

# -----------
# Target Benchmarks
# -----------
if(BUILD_BENCHMARKS)
    add_subdirectory(benchmarks)
endif()



###########
# Install #
###########

# Install header files
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/flatmemory"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")


###########
# Exports #
###########

# https://cmake.org/cmake/help/latest/guide/importing-exporting/index.html

include(CMakePackageConfigHelpers)

# Generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/flatmemoryConfigVersion.cmake"
    VERSION ${flatmemory_VERSION}
    COMPATIBILITY ExactVersion
)

# Create config file
# https://cmake.org/cmake/help/book/mastering-cmake/cmake/Help/guide/importing-exporting/index.html
# https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html#generating-a-package-configuration-file
configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/flatmemoryConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/flatmemory"
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# Install config files
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/flatmemoryConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/flatmemoryConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/flatmemory"
)