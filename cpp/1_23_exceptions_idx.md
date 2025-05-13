<a name="1_23_exceptions-1"></a>
# Runtime Errors & Exception Handling   

- C++ provides multiple mechanisms to handle runtime errors, including:
    - assertions
    - exceptions
    - `noexcept`


<a name="1_23_exceptions-1-1"></a>
##  Assertions (`assert`)  

- Used to check preconditions/invariants (usually) **in debug builds**
    - `NDEBUG` macro disables it in Release mode.  
- Terminates the program if a condition fails.  

```cpp
#include <cassert>

int divide(int a, int b) {
    assert(b != 0 && "Division by zero!"); // Catches division by zero in debug mode
    return a / b;
}

int main() {
    int result = divide(10, 0); // Triggers assertion failure
    return 0;
}
```


<a name="1_23_exceptions-1-2"></a>
## Exception Handling (`try`, `catch`, `throw`)  

- C++ uses **exceptions** to handle runtime errors safely.  
- Errors are **thrown** using `throw`, **caught** using `catch`, and handled inside a `try` block.  

```cpp
#include <iostream>
#include <stdexcept> // For standard exceptions

int safeDivide(int a, int b) {
    if (b == 0) throw std::runtime_error("Division by zero error!"); // Throws an exception
    return a / b;
}

int main() {
    try {
        int result = safeDivide(10, 0); // Throws exception
        std::cout << "Result: " << result << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n'; // Handles error
    }

    return 0;
}
```

- `throw` raises an exception.  
- `try` block wraps **code that may fail**.  
- `catch` handles exceptions gracefully.  


<a name="1_23_exceptions-1-2-1"></a>
### Catching Different Exceptions

- You can catch **specific** or **all** exceptions.
- Go top-down from more specific to more general exceptions.

```cpp
try {
    throw std::out_of_range("Index out of range");
} catch (const std::out_of_range& e) {  
    std::cerr << "Caught out_of_range: " << e.what() << '\n';
} catch (const std::exception& e) {  
    std::cerr << "Caught generic exception: " << e.what() << '\n';
} catch (...) {  
    std::cerr << "Caught unknown exception\n";  // Catches everything
}
```


<a name="1_23_exceptions-1-3"></a>
## `noexcept`: Declaring Non-Throwing Functions

- `noexcept` tells the compiler that a function **won't throw exceptions**.  
- It **enables compiler optimizations** and improves **performance**.
- If a `noexcept` function throws, `std::terminate()` is called.

```cpp
void safeFunction() noexcept {
    // Guarantees no exceptions
}

void riskyFunction() noexcept(false) {
    throw std::runtime_error("Error!"); // Exception allowed
}
```

<a name="1_23_exceptions-1-4"></a>
## Standard Exception Hierarchy (`std::exception`)

- C++ provides a **hierarchy of exceptions** in `<stdexcept>`.

<a name="1_23_exceptions-1-4-1"></a>
### Base Class: `std::exception`

- All standard exceptions derive from `std::exception`.

```cpp
#include <iostream>
#include <exception>

int main() {
    try {
        throw std::runtime_error("Something went wrong!");
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n'; // Prints error message
    }
}
```
↪ `what()` returns an error message.  

<a name="1_23_exceptions-1-4-2"></a>
### Common Standard Exceptions

| Exception            | Description |
|----------------------|-------------|
| `std::runtime_error` | Generic runtime error |
| `std::logic_error`   | Logical program error (e.g., violating preconditions) |
| `std::out_of_range`  | Accessing out-of-bounds elements |
| `std::invalid_argument` | Invalid function arguments |
| `std::bad_alloc`     | Memory allocation failure (`new` failed) |
| `std::overflow_error` | Arithmetic overflow |
| `std::underflow_error` | Arithmetic underflow |

```cpp
try {
    throw std::out_of_range("Index out of bounds");
} catch (const std::out_of_range& e) {
    std::cerr << "Out of range: " << e.what() << '\n';
}
```

<a name="1_23_exceptions-1-5"></a>
## Learn More

- [Standard Exceptions](https://en.cppreference.com/w/cpp/header/exception)

---
[[⇦ Previous](1_22_static_errors_idx.md)]		[[Next  ⇨](1_24_error_as_values_idx.md)]		[[Index ⇧](index.md#1_23_exceptions_idx.md)]
