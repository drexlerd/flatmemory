find_package(benchmark "1.8.3" REQUIRED benchmark Main PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
# Set result variables
find_package(benchmark)

add_executable(bitset_builder "bitset_builder.cpp")
target_link_libraries(bitset_builder 
    PRIVATE 
        flatmemory::flatmemory
        benchmark::benchmark)

add_executable(bitset_view "bitset_view.cpp")
target_link_libraries(bitset_view 
    PRIVATE 
        flatmemory::flatmemory
        benchmark::benchmark)

