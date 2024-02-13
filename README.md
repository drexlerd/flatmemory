# Flatmemory

Flatmemory is a C++20 library for serializing nested data types into a sequence of bytes with zero-cost deserialization. Flatmemory can be used to decrease memory allocations and to obtain better cache locality. Flatmemory computes the memory layouts at compile time. Flatmemory reuses memory during the construction of buffers. Flatmemory provides containers to store the buffers that require only a few memory allocations for a storing a collection of buffers.

Flatmemory currently provides the following non-trivial composite types:

- Tuple
- Vector
- Bitset

All non-trivial types support all non-trivial types and types `T` that satisfy `std::is_trivially_copyable_v<T>` as nested types. The data of non-trivial types are stored with an offset of type `uint16_t` and all other types `T` are stored in-place.

Comparison to related libraries such as flatbuffers or cap'n'proto:

Advantages:
  - Availability of useful non-trivial types with reduced size of vtables
  - Availability of general containers to store byte sequences: FixedSizedTypeVector, VariableSizedTypeVector, UnorderedSet
  - No code generator is needed

Disadvantages:
  - Memory layouts cannot be extended while supporting backward compatibility


## Example

In this example, we use a `Builder`to serialize a 2-dimensional `Vector` of `uint16_t` into a sequence of bytes. A respective `View` can interpret the data.

```cpp
#include <flatmemory/flatmemory.hpp>

// 1. Type the dispatcher.
using TwoDimVecUint16 = Vector<Vector<uint16_t>>;

// 2. Print the static layout
Layout<TwoDimVecUint16>().print()

// 3. Construct a builder, feed it with data, and finish the byte sequence.
auto builder = Builder<TwoDimVecUint16>();
builder.resize(2);
builder[0].push_back(5);
builder[1].push_back(6);
builder[1].push_back(7);
builder.finish();
EXPECT_EQ(builder.get_size(), 36);

// 4. Construct a view to interpret the byte sequence.
auto view = View<TwoDimVecUint16>(builder.get_data());
EXPECT_EQ(view.buffer_size(), 36);  // storing views contiguously satisfies alignment requirements
EXPECT_EQ(view.size(), 2);
EXPECT_EQ(view[0][0], 5);
EXPECT_EQ(view[1][0], 6);
EXPECT_EQ(view[1][1], 7);
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
target_link_libraries(<your_target> flatmemory::flatmemory)
```


## For Developers

We provide a CMake Superbuild project that takes care of downloading, building, and installing all dependencies.

```console
# Configure dependencies
cmake -S dependencies -B dependencies/build -DCMAKE_INSTALL_PREFIX=dependencies/installs
# Build and install dependencies
cmake --build dependencies/build -j16
```

Flatmemory's testing framework depends on [GoogleTest](https://github.com/google/googletest) and requires the additional compile flag `-DBUILD_TESTS=ON` to be set in the cmake configure step.

Flatmemory's performance framework depends on [GoogleBenchmark](https://github.com/google/benchmark) and requires the additional compile flag `-DBUILD_BENCHMARKS=ON` to be set in the cmake configure step. The results from the GitHub action can be viewed [here](https://drexlerd.github.io/flatmemory/dev/bench/).
