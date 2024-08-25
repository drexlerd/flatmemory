enable_testing()

find_package(GTest "1.11.0" REQUIRED COMPONENTS GTest Main PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
# Set result variables
find_package(GTest)

set(TEST_NAME ${CMAKE_PROJECT_NAME}_tests)

add_executable(${TEST_NAME}
    "containers/unordered_set.cpp"
    "containers/vector.cpp"
    "types/bitset.cpp"
    "types/optional.cpp"
    "types/tuple.cpp"
    "types/vector.cpp"
    "types/typed_vector.cpp"
)

target_link_libraries(${TEST_NAME}
    PRIVATE
        flatmemory::flatmemory
        GTest::GTest
        GTest::Main)

add_test(domain_gtests ${TEST_NAME})

