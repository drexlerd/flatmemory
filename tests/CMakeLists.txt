enable_testing()

find_package(GTest "1.11.0" REQUIRED COMPONENTS GTest Main PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
# Set result variables
find_package(GTest)

file(GLOB_RECURSE FLATMEMORY_TEST_SOURCE_FILES
    "*.cpp" "**/*.cpp")
file(GLOB_RECURSE FLATMEMORY_TEST_SOURCE_FILES
    "*.hpp" "**/*.hpp")

set(TEST_NAME ${CMAKE_PROJECT_NAME}_tests)

add_executable(${TEST_NAME}
    "types/tuple.cpp"
    "types/vector.cpp"
)

target_link_libraries(${TEST_NAME}
    PRIVATE
        GTest::GTest
        GTest::Main)
target_include_directories(${TEST_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_test(domain_gtests ${TEST_NAME})

