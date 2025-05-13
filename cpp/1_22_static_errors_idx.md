<a name="1_22_static_errors-1"></a>
# Error Handling

- Errors can be treated at compile and/or runtime.


<a name="1_22_static_errors-2"></a>
# Compile Time (static) Error-check

- Detect and prevent incorrect usage before the program runs. 

<a name="1_22_static_errors-2-1"></a>
## `static_assert`: Compile Time Assertions (C++11)

- `static_assert` allows checking conditions at compile time. 
- The condition must be testable at compile time.
- If the condition is false, compilation **fails** with an error message.

```cpp
// Example: Ensuring an Integer Type
template <typename T>
void process() {
    static_assert(std::is_integral<T>::value, "T must be an integral type!");
}
int main() {
    process<int>();   // OK Compiles
    process<double>(); // Compilation Error: "T must be an integral type!"
}
```

<a name="1_22_static_errors-2-2"></a>
## `constexpr` for Compile-time Evaluation (C++11)

- A `constexpr` function may be evaluate at compile time ensuring correctness before runtime.

```cpp
constexpr int factorial(int n) { // evaluates at compile time if n is a constant expression
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

static_assert(factorial(5) == 120, "Factorial calculation is incorrect!");
```

<a name="1_22_static_errors-2-3"></a>
## SFINAE (Substitution Failure Is Not An Error)


- SFINAE helps detect invalid template instantiations

```cpp
// Example: Enable Function Only for Integers
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type foo(T) {
    // Only works for integral types
}

int main() {
    foo(10);     // OK, int is integral
    foo(3.14);   // Compilation Error
}
```

<a name="1_22_static_errors-2-4"></a>
## Type Traits 

- Type traits in `<type_traits>` allows for compile-time type checks.

```cpp
template <typename T>
void check() {
    static_assert(std::is_same<T, int>::value, "T must be int!");
}

check<int>();    // OK
check<double>(); // Compilation Error
```

<a name="1_22_static_errors-2-5"></a>
## Prevent Instantiation Using Deleted Functions

- You can **prevent instantiation** of certain templates by deleting them.

```cpp
template <typename T>
class Example {};

// Explicitly disable `double`
template <>
class Example<double> = delete;

Example<int> obj1;   // OK
Example<double> obj2; // Compilation Error
```

<a name="1_22_static_errors-2-6"></a>
## `concepts` (C++20)

- C++20 introduces **concepts** to enforce type constraints at compile time.

```cpp
#include <concepts>

template <std::integral T> // Requires `T` to be an integer
void process(T value) {}

process(10);     //  OK
process(3.14);   //  Compilation Error
```

<a name="1_22_static_errors-2-7"></a>
## Learn more

- [Type traits](https://en.cppreference.com/w/cpp/meta#Type_traits)
- [Concepts](https://en.cppreference.com/w/cpp/concepts)

---
[[⇦ Previous](1_21_templates_metaprogramming_idx.md)]		[[Next  ⇨](1_23_exceptions_idx.md)]		[[Index ⇧](index.md#1_22_static_errors_idx.md)]
