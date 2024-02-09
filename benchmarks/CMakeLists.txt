find_package(benchmark "1.8.3" REQUIRED benchmark Main PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
# Set result variables
find_package(benchmark)

add_executable(bitset "bitset.cpp")
target_link_libraries(bitset 
    PRIVATE 
        flatmemory::flatmemory
        benchmark::benchmark)

