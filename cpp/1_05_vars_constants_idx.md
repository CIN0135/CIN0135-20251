<a name="1_05_vars_constants-1"></a>
# Variables and Constants

<a name="1_05_vars_constants-1-1"></a>
## Primitive Types

| **Category**        | **Type**             | **Size (Typical)** | **Description** |
|---------------------|---------------------|--------------------|----------------|
| **Boolean**        | `bool`              | 1 byte            | Represents `true` or `false` |
| **Character**      | `char`              | 1 byte            | ASCII character (or small integer) |
|                   | `wchar_t`           | 2-4 bytes         | Wide character (Unicode) |
|                   | `char8_t` (C++20)   | 1 byte            | UTF-8 character |
|                   | `char16_t` (C++11)  | 2 bytes           | UTF-16 character |
|                   | `char32_t` (C++11)  | 4 bytes           | UTF-32 character |
| **Integer (Signed)** | `short`            | 2 bytes           | Short integer (-32,768 to 32,767) |
|                   | `int`               | 4 bytes           | Standard integer |
|                   | `long`              | 4 or 8 bytes      | Larger integer (at least 4 bytes) |
|                   | `long long` (C++11) | 8 bytes           | 64-bit integer |
| **Integer (Unsigned)** | `unsigned short` | 2 bytes           | Unsigned short (0 to 65,535) |
|                   | `unsigned int`      | 4 bytes           | Unsigned integer (0 to 4,294,967,295) |
|                   | `unsigned long`     | 4 or 8 bytes      | Unsigned long integer |
|                   | `unsigned long long` | 8 bytes          | Unsigned 64-bit integer |
| **Floating Point** | `float`             | 4 bytes           | Single precision floating-point |
|                   | `double`            | 8 bytes           | Double precision floating-point |
|                   | `long double`       | 8-16 bytes        | Extended precision floating-point |
| **Void**          | `void`              | N/A               | Represents "no type" (used in functions) |
| **Null Pointer**  | `nullptr_t` (C++11) | N/A               | Type for `nullptr` |

<a name="1_05_vars_constants-1-1-1"></a>
### Note

- **Sizes vary** depending on the system architecture (e.g., 32-bit vs. 64-bit).
- **`long` and `long long`**: The size of `long` is platform-dependent but is at least **4 bytes**. `long long` is guaranteed to be **8 bytes**.
- **Wide character types** (`wchar_t`, `char16_t`, `char32_t`) are useful for Unicode support.
- **`nullptr_t`** is the type of the `nullptr` constant introduced in C++11.
  

<a name="1_05_vars_constants-1-2"></a>
## Enumerations (Enums)

- An **enum** is a user-defined type that consists in a set of named integral constants. 
- It improves code readability and maintainability by replacing magic numbers with meaningful names.  

<a name="1_05_vars_constants-1-2-1"></a>
### Basic enums

- With default **int** values: `Red = 0`, `Green = 1`, `Blue = 2`.

```cpp
enum Color { Red, Green, Blue };
```

- With explicitly assigned values.

```cpp
enum Color { Red = 1, Green = 5, Blue = 10 };
```

- With explicitly specified underlying type (default is `int`):

```cpp
enum class Color : uint8_t { Red = 1, Green = 2, Blue = 3 };
```

<a name="1_05_vars_constants-1-2-2"></a>
###  Scoped `enum class` (C++11)

```cpp
enum class Color { Red, Green, Blue };

int main() {
    //...
    Color c;
    //...
    if (c == Color::Green) { 
        //...
    }
    // ...
    int redValue = static_cast<int>(Color::Red); // explicit conversion required
    // ...
}
```
- **Scoped**: Access values using `Color::Red`.  
- **Type-safe**: Cannot implicitly convert to `int`.  


<a name="1_05_vars_constants-1-3"></a>
## Variables

* Used for mutable values

```cpp
int main() {
    // declaration only (be careful)
    int a; // unititalized !

    // copy initialization
    int b = 1;  
    int c = 2.0;  // narrowing convertion
    unsigned int d = -3; // signal loss convertion
    double e = 3; // Implicitly converts int to double
    double f = 3.0; 

    // Direct list initialization (C++11)
    long g{4L};
    long h{5};  // implicitly converts int to long
    long i{6.0}; // ERROR: narrowing convertion
}
```

<a name="1_05_vars_constants-1-4"></a>
## Pointers

- A **pointer** is a variable that stores the memory address of another variable.  

```cpp
int x = 10;
int* ptr = &x;  // ptr holds the address of x
std::cout << *ptr; // Output: 10
*ptr = 20;
std::cout << x; // Output: 20
```

- Operators: 
    - `&x` → Memory address of `x`
    - `*ptr` → Dereferencing: Accesses the value stored at that address  

<a name="1_05_vars_constants-1-4-1"></a>
###  Null and Void Pointers

```cpp
int* p = nullptr; // A null pointer (does not point to any valid memory)
void* vp;         // A void pointer (can hold any data type's address)
```

<a name="1_05_vars_constants-1-5"></a>
## Constants

* Used for unmutable values

```cpp
const double PI = 3.1415;
int main() {
   PI = 2.79; // ERROR: assignment to read-only value
}
```

<a name="1_05_vars_constants-1-6"></a>
## Type aliases

- Creates an alias (alternative name) for an existing type for better readability.

<a name="1_05_vars_constants-1-6-1"></a>
### `typedef` (Legacy)

```cpp
// Creating an alias for `unsigned int
typedef unsigned int uint;

int main(){ 
    uint x = 42;  // Equivalent to `unsigned int x = 42;
    // ...
}
```

<a name="1_05_vars_constants-1-6-2"></a>
### `using` (C\+\+11, Preferred in Modern C++ )

```cpp
// Creating an alias for `unsigned int`
using uint = unsigned int;

int main() {
    uint y = 100;
    // ...
}
```

<a name="1_05_vars_constants-1-6-3"></a>
### Advantages of `using` over `typedef`

- `using` allows template aliases. (see [templates]()) 

```cpp
#include <vector>
// Define a template alias for a vector of integers
template <typename T>
using Vec = std::vector<T>;
Vec<int> numbers;  // Equivalent to std::vector<int>
```

- Better syntax for function pointers (see [functions]() and [pointers]())

```cpp
typedef void (*FuncPtr)(int);  // A function pointer alias
void print(int x) { std::cout << x << std::endl; }
FuncPtr f = print;
using FuncPtr = void(*)(int);
void print(int x) { std::cout << x << std::endl; }
FuncPtr f = print;
```

<a name="1_05_vars_constants-1-7"></a>
## Compile-time Constant Expressions

The `constexpr` keyword in C++ (introduced in C++11 and improved in later versions) is used to indicate that a function or variable **can be evaluated at compile time**, enabling better performance and optimization.


<a name="1_05_vars_constants-1-7-1"></a>
### `constexpr` Variables 

- Must be **constant and known at compile time**.

```cpp
constexpr double PI = 3.14159; // OK: Known at compile time

int main() {
    double radius = 2.0d;
    double area = pi * radius * radius;
}
```

<a name="1_05_vars_constants-1-7-2"></a>
### `constexpr` Functions  

- Can be evaluated at compile time if called with constant inputs but can also run at runtime if needed.

```cpp
constexpr double PI = 3.14159; // OK: Known at compile time

constexpr double square(double x) { return x * x; }

constexpr int BASEL_SUM = square(PI) / 6.0d; // Computed at compile time

int main() {
    double radius;
    // read radius from user input
    double circleArea = PI * square(radius); // Computed at runtime
}
```

<a name="1_05_vars_constants-1-7-3"></a>
### `constexpr` and `if constexpr` (C++17)  

C++17 introduced `if constexpr`, which allows **compile-time branching** inside `constexpr` functions.

```cpp
#include <iostream>
#include <type_traits>

template <typename T> void printTypeInfo(const T &value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral value: " << value << '\n';
    } else {
    std::cout << "Non-integral value: " << value << '\n';
    }
}

int main() {
    printTypeInfo(42);   // Output: Integral value: 42 
    printTypeInfo(3.14); // Output: Non-integral value: 3.14
}
```

- **`if constexpr`** ensures that only the **relevant** branch is compiled, optimizing the code.


<a name="1_05_vars_constants-1-7-4"></a>
### `constexpr` Constructors & Objects**

C++ allows objects to be `constexpr` if they have **constexpr constructors**.

```cpp
struct Point {
    constexpr Point(int x, int y) : x(x), y(y) {}
    constexpr int getX() const { return x; }
    constexpr int getY() const { return y; }

private:
    int x, y;
};

constexpr Point p1(3, 4); // OK: Compile-time object
constexpr int xVal = p1.getX(); // OK: Compile-time access
```

---
[[⇦ Previous](1_04_main_idx.md)]		[[Next  ⇨](1_06_control_flow_idx.md)]		[[Index ⇧](index.md#1_05_vars_constants_idx.md)]
