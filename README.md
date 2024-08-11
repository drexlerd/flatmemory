# Flatmemory

Flatmemory is a C++20 library for serialization and zero-cost deserialization. Serialization is the problem of creating sequential representation of an object, and zero-cost deserialization is the problem of accessing the data without creating the original object. Flatmemory uses the typical approach of using builders for serialization and views for deserialization. The main advantage of this approach over compiler-generated memory layouts is that it requires much fewer (almost zero) memory allocations when creating objects since the memory of the builders is reused, and serialized data can be written to large preallocated buffers. Another advantage is that data is stored contiguously in memory, improving cache locality and resulting in better runtimes. The main disadvantage is that serialized objects cannot grow in their size. Flatmemory shines when creating many immutable objects that remain persistent in memory.

Flatmemory currently provides the following non-trivial composite types:

- Tuple
- Vector
- Bitset

The supported nested types are all non-trivial types and trivial types `T` that satisfy `std::is_trivially_copyable_v<T>`. The data of non-trivial types is stored with an offset of type `uint32_t` and the data of all trivial types `T` is stored in-place. All non-trivial types are prefixed with a `uint32_t` that represents the size of the buffer with the exception of `Trivial` where `sizeof(T)` represents the buffer size.

Comparison to related libraries such as flatbuffers or cap'n'proto:

Advantages:
  - No code generator is needed

Disadvantages:
  - Memory layouts cannot be extended while supporting backward compatibility


## Example

In this example, we use a `Builder`to serialize a 2-dimensional `Vector` of `uint16_t` into a sequence of bytes. A respective `View` can interpret the data.

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
