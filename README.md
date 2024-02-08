# Flatmemory

Flatmemory is a C++20 header-only library for serializing nested data types into a sequence of bytes with zero-cost deserialization. Flatmemory can be used to decrease memory allocations to almost zero and to obtain better cache locality. Flatmemory computes the memory layouts at compile time.

Flatmemory currently provides the following non-trivial composite types:

- Tuple
- Vector
- Bitset

All non-trivial types support all non-trivial types and types `T` that satisfy `std::is_trivially_copyable_v<T>` as nested types.

## Example

In this example, we use a `Builder`to serialize a 2-dimensional `Vector` of `uint16_t` into a sequence of bytes. A respective `View` can interpret the data.

```cpp
#include <flatmemory/flatmemory.hpp>

// 1. Layout requirement 
EXPECT_EQ((Layout<Vector<Vector<uint16_t>>>::final_alignment), 4);

// 2. Construct a builder, feed it with data, and finish the byte sequence.
auto builder = Builder<Vector<Vector<uint16_t>>>();
builder.resize(2);
builder[0].push_back(5);
builder[1].push_back(6);
builder[1].push_back(7);
builder.finish();
assert(builder.get_data() != nullptr);
assert(builder.get_size() == 36);

// 3. Construct a view to interpret the byte sequence.
auto view = View<Vector<Vector<uint16_t>>>(builder.get_data());
EXPECT_EQ(view.buffer_size(), 36);  // storing views contiguously satisfies alignment requirements
EXPECT_EQ(view.size(), 2);
EXPECT_EQ(view[0][0], 5);
EXPECT_EQ(view[1][0], 6);
EXPECT_EQ(view[1][1], 7);

// 3. Clear the builder to reuse its memory for successive creation of objects
builder.clear();
```


## Getting Started

We recommend the following sequence of cmake commands to install the headers. No build step required.

```console
cmake -S . -B build -DCMAKE_INSTALL_DIR="path/to/install/dir"
cmake --install build
```

We recommend adding the following to your root `CMakeLists.txt` for making the headers available for your CMake project where `CMAKE_PREFIX_PATH` is the installation directory

```cmake
find_package(flatmemory REQUIRED PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
if(flatmemory_FOUND)
  include_directories(${flatmemory_INCLUDE_DIRS})
  message(STATUS "Found flatmemory: ${flatmemory_DIR} (found version ${flatmemory_VERSION})")
endif()
```


## For Developers

Flatmemory's testing framework depends on [GoogleTest](https://github.com/google/googletest).

We provide a CMake Superbuild project that takes care of downloading, building, and installing all dependencies.

```console
# Configure dependencies
cmake -S dependencies -B dependencies/build -DCMAKE_INSTALL_PREFIX=dependencies/installs
# Build and install dependencies
cmake --build dependencies/build -j16
```
