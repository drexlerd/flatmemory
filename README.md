# Flatmemory

Flatmemory is a header-only C++20 library for serializing nested data types into a sequence of bytes and zero cost deserialization.


## Getting Started

### Installing the Dependencies

Flatmemory depends on [GoogleTest](https://github.com/google/googletest).

We provide a CMake Superbuild project that takes care of downloading, building, and installing all dependencies.

```console
# Configure dependencies
cmake -S dependencies -B dependencies/build -DCMAKE_INSTALL_PREFIX=dependencies/installs
# Build and install dependencies
cmake --build dependencies/build -j16
```


### Including Headers

```cpp
if(flatmemory_FOUND)
  include_directories(${flatmemory_INCLUDE_DIRS})
  message(STATUS "Found flatmemory: ${flatmemory_DIR} (found version ${flatmemory_VERSION})")
endif()
```