file(GLOB_RECURSE FLATMEMORY_SRC_FILES
   "*.cpp" "**/*.cpp")
file(GLOB_RECURSE FLATMEMORY_PRIVATE_HEADER_FILES
    "*.hpp" "**/*.hpp")
file(GLOB_RECURSE FLATMEMORY_PUBLIC_HEADER_FILES
    "../include/*.hpp" "../include/**/*.hpp")

add_library(flatmemory STATIC ${FLATMEMORY_SRC_FILES} ${FLATMEMORY_PRIVATE_HEADER_FILES} ${FLATMEMORY_PUBLIC_HEADER_FILES})

# Create an alias for simpler reference
add_library(flatmemory::flatmemory ALIAS flatmemory)

# Use include depending on building or using from installed location
target_include_directories(flatmemory
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# Install the target and create export-set
install(
    TARGETS flatmemory
    EXPORT flatmemoryTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Generate and install export file
install(EXPORT flatmemoryTargets
    NAMESPACE flatmemory::
    COMPONENT flatmemory
    FILE "flatmemoryTargets.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/flatmemory"
)

# Generate build tree export file
export(EXPORT flatmemoryTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/flatmemoryTargets.cmake"
    NAMESPACE flatmemory::
)
