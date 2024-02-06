# Flatmemory

Flatmemory is a C++20 header-only library for serializing nested data types into a sequence of bytes and zero cost deserialization.

## Example

In this example, we serialize a 2-dimensional `Vector` of `uint16_t` into a sequence of bytes. The respective view can interpret the data.

```cpp
auto builder = Builder<Vector<Vector<uint16_t>>>();
builder.get_builders().resize(2);
builder.get_builders()[0].get_builders().push_back(5);
builder.get_builders()[1].get_builders().push_back(6);
builder.get_builders()[1].get_builders().push_back(7);
builder.finish();
assert(builder.get_data() != nullptr);
assert(builder.get_size() == 24);

auto view = View<Vector<Vector<uint16_t>>>(builder.get_data());
assert(view.get_size() == 2);
assert(view[0][0] == 5);
assert(view[1][0] == 6);
assert(view[1][1] == 7);
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