<a name="1_01_intro-1"></a>
# Introduction to Modern C++

<a name="1_01_intro-1-1"></a>
## What is C++

- C++ is a high-performance, general-purpose programming language that combines procedural, object-oriented, and generic programming paradigms. 
- Originally developed by Bjarne Stroustrup in the early 1980s as an extension of C.
- Offers direct memory management, low-level system access, and high efficiency while also supporting abstraction and modularity. 
- Widely used in systems programming, game development, real-time applications, and performance-critical software.
- C++ is standardized by the International Organization for Standardization (ISO) through the C++ Standard Committee. 
- The first official standard, C++98, was published in 1998, and since then, the language has evolved through successive standards released approximately every three years. 
- Each new standard has introduced major improvements in expressiveness, safety, and performance.

<a name="1_01_intro-1-2"></a>
## Evolution from C\+\+98 to C\+\+20

- **C++98 (1998)**: Introduced the Standard Template Library (STL), including containers, iterators, and algorithms.
- **C++03 (2003)**: Primarily a bug-fix release with minor enhancements.
- **C++11 (2011) - "Modern C++ Begins"**:
  - Move semantics (`std::move`, `std::unique_ptr`)
  - Smart pointers (`std::shared_ptr`, `std::weak_ptr`)
  - Lambda functions
  - Range-based for loops
  - `auto` type deduction
  - `nullptr`, `constexpr`, `enum class`
- **C++14 (2014)**: Small refinements to C++11 (e.g., generic lambdas, `std::make_unique`).
- **C++17 (2017)**:
  - `std::optional`, `std::variant`, and `std::any`
  - `std::filesystem`
  - Structured bindings (`auto [x, y] = pair;`)
  - Parallel algorithms in the STL
- **C++20 (2020) - "The Next Big Leap"**:
  - Concepts (for better template constraints)
  - Coroutines
  - Ranges library
  - `std::span` for safer array handling
  - Modules (replacing traditional header files)
  - `constexpr` expansion (more compile-time computations)


<a name="1_01_intro-1-3"></a>
## Key Features of Modern C++

- **Move Semantics**: Optimizes performance by avoiding deep copies.
- **Smart Pointers**: Eliminates manual memory management errors.
- **Lambdas & Functional Programming**: Allows concise inline function expressions.
- **Type Deduction (`auto`, `decltype`)**: Reduces verbosity while improving readability.
- **Ranges & Algorithms**: Simplifies iteration and data manipulation.
- **Coroutines**: Enables more efficient asynchronous programming.
- **Modules**: Reduces compile times and eliminates header file complexities.
- **Better Multi-threading Support**: `std::thread`, `std::async`, `std::mutex`, `std::atomic`.

<a name="1_01_intro-1-4"></a>
## Why C++ is Still Relevant Today

Despite the rise of newer languages like Rust and Go, C++ remains widely used due to:

1. **Performance & Efficiency**: Unlike managed languages (e.g., Java, C#), C++ gives direct control over memory and system resources.
2. **Embedded Systems & Game Development**: Used in real-time systems, gaming engines (Unreal Engine), and high-performance applications.
3. **Large-Scale Applications**: Banks, aerospace, automotive, and robotics heavily rely on C++.
4. **Cross-Platform Development**: Code can be compiled for Windows, Linux, macOS, and embedded systems with minimal modifications.
5. **Backbone of Modern Languages**: C++ influences languages like Rust, Swift, and C#.


---
[[⇦ Previous](index.md)]		[[Next  ⇨](1_02_csharp_vs_cpp_idx.md)]		[[Index ⇧](index.md#1_01_intro_idx.md)]
