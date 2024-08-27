# Flatmemory

Flatmemory is a C++20 library for serialization and zero-cost deserialization. Serialization is the problem of creating sequential representation of an object, and zero-cost deserialization is the problem of accessing the data without creating the original object. Flatmemory uses the typical approach by employing builders for serialization and views for deserialization, offering significant performance advantages over traditional compiler-generated memory layouts.

## Key Features and Advantages

1. **Efficient Memory Management:** Flatmemory excels in scenarios where minimal memory allocations are critical. Builders reuse their memory, and serialized data can be efficiently written to large preallocated buffers. This minimizes the overhead typically associated with object creation and memory management.
2. **Cache-Friendly Data Layout:** Flatmemory stores data contiguously in memory, enhancing cache locality.
3. **Non-Trivial and Trivial Types:** Flatmemory supports a variety of non-trivial composite types like `Tuple`, `Vector`, `Optional`, and `Bitset`. Trivial types `T` that satisfy `std::is_trivially_copyable_v<T>` are stored in place, while non-trivial types are managed using offsets of type `uint32_t`.
4. **Generic Programming:** Unlike other serialization libraries, Flatmemory does not rely on code generation tools. Instead, Flatmemory is purely based on templates, allowing serialization of generic types at ease.

## Limitations

1. **Fixed Memory Layouts:** Once an object is serialized, its memory layout cannot be extended while maintaining backward compatibility. However, the library can be extended to work for such use cases as well.
2. **Non-Resizable Objects:** Serialized objects have a fixed size, and operations that would alter their structure (such as inserting elements in a vector) are not permitted. Instead, the user has to reconstruct a new buffer. Mutating trivially copieable types is possible.

## Example

In this example, we use a `Builder` to serialize a 2-dimensional `Vector` of `uint16_t` into a sequence of bytes. A respective `View` can interpret the data. For a sequence of `N` insert operations, zero memory allocations on average are needed to construct a two dimensional vector (assuming a fixed size), and the usual `log(N)` memory allocations are needed to store them in a buffer that uses doubling strategy for memory allocation. Instead of reallocating memory, an additional buffer segment of double the size is allocated to ensure that existing views do not become invalidated.

```cpp
#include <flatmemory/flatmemory.hpp>

// 1. Type def the Dispatcher.
using TwoDimVecUint16 = Vector<Vector<uint16_t>>;

// 2. Print the static Layout
Layout<TwoDimVecUint16>().print()

// 3. Construct a Builder, feed it with data, and finish the byte sequence.
auto builder = Builder<TwoDimVecUint16>();
builder.resize(2);
builder[0].push_back(5);
builder[1].push_back(6);
builder[1].push_back(7);
builder.finish();
EXPECT_EQ(builder.get_size(), 36);

// 4. Construct a mutable View to interpret and modify (with limitations) the byte sequence.
auto view = View<TwoDimVecUint16>(builder.get_data());
EXPECT_EQ(view.buffer_size(), 36);
EXPECT_EQ(view.size(), 2);
EXPECT_EQ(view[0][0], 5);
EXPECT_EQ(view[1][0], 6);
EXPECT_EQ(view[1][1], 7);

// 5. Construct a immutable ConstView to interpret the byte sequence.
auto const_view = ConstView<TwoDimVecUint16>(builder.get_data());
EXPECT_EQ(const_view.buffer_size(), 36);
EXPECT_EQ(const_view.size(), 2);
EXPECT_EQ(const_view[0][0], 5);
EXPECT_EQ(const_view[1][0], 6);
EXPECT_EQ(const_view[1][1], 7);

// 6. Insert a buffer into a set either using Builder, View, or ConstView
auto unordered_set = UnorderedSet<TwoDimVecUint16>();
auto const_view1 = unordered_set.insert(builder);
auto const_view2 = unordered_set.insert(view);
auto const_view3 = unordered_set.insert(const_view);
EXPECT_EQ(const_view1, const_view2);
EXPECT_EQ(const_view2, const_view3);
```


## Getting Started

### Installing the Dependencies

Flatmemory depends on the following set of libraries:

- [GoogleBenchmark](https://github.com/google/benchmark) for automated performance benchmarking, and
- [GoogleTest](https://github.com/google/googletest) for unit testing.

Run the following sequence of commands to download, configure, build, and install all dependencies:

```console
# Configure dependencies
cmake -S dependencies -B dependencies/build -DCMAKE_INSTALL_PREFIX=dependencies/installs
# Build and install dependencies
cmake --build dependencies/build -j16
```

### Configuring and Building Flatmemory

Run the following sequence of commands to configure, build, and install Flatmemory:

```console
# Configure with installation prefixes of all dependencies
cmake -S . -B build -DCMAKE_PREFIX_PATH=${PWD}/dependencies/installs
# Build
cmake --build build -j16
# Install (optional)
cmake --install build --prefix=<path/to/installation-directory>
```

We recommend adding the following to your root `CMakeLists.txt` for making the headers available for your CMake project where `CMAKE_PREFIX_PATH` is the installation directory

```cmake
find_package(flatmemory REQUIRED PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
target_link_libraries(<your_target> flatmemory::flatmemory)
```

## For Developers

Flatmemory's testing framework depends on [GoogleTest](https://github.com/google/googletest) and requires the additional compile flag `-DBUILD_TESTS=ON` to be set in the cmake configure step.

Flatmemory's performance framework depends on [GoogleBenchmark](https://github.com/google/benchmark) and requires the additional compile flag `-DBUILD_BENCHMARKS=ON` to be set in the cmake configure step. The results from the GitHub action can be viewed [here](https://drexlerd.github.io/flatmemory/dev/bench/).
