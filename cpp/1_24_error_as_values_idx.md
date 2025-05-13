<a name="1_24_error_as_values-1"></a>
# Errors As Values

- Handle errors using return values, providing better performance and control. 
- Two commonly used approaches involve `std::optional` and `std::variant`.


<a name="1_24_error_as_values-1-1"></a>
## Representing Optional Values - `std::optional` (C++17)

- `std::optional<T>` represents an object that may or may not contain a value. 
- Useful for functions that might fail but don't need to differentiate causes or give an explicit error message.
- Avoids exception overhead.

```cpp
#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b) {
    if (b == 0) return std::nullopt; // No value in case of error
    return a / b;
}

int main() {
    auto result = divide(10, 2);
    
    if (result) {
        std::cout << "Result: " << *result << '\n';
    } else {
        std::cout << "Error: Division by zero!\n";
    }
}
```

<a name="1_24_error_as_values-1-2"></a>
## Representing Multiple Possible Outcomes - `std::variant` (C++17)

- `std::variant<T1, T2, ...>` allows returning either a valid result or an error code/message in a type-safe way.

```cpp
#include <iostream>
#include <variant>
#include <string>

using Result = std::variant<int, std::string>;

Result divide(int a, int b) {
    if (b == 0) return std::string("Error: Division by zero");
    return a / b;
}

int main() {
    Result result = divide(10, 0);

    if (std::holds_alternative<int>(result)) {
        std::cout << "Result: " << std::get<int>(result) << '\n';
    } else {
        std::cerr << "ERROR:" << std::get<std::string>(result) << '\n';
    }
}
```

<a name="1_24_error_as_values-1-3"></a>
## Comparison 

| Feature | `std::optional` | `std::variant` |
|---------|----------------|----------------|
| Use case | Success or failure without detailed error info | Multiple possible outcomes (value or error) |
| Error details | No | Yes |
| Overhead | Lower | Slightly higher |
| Simplicity | Very simple | Less simple |

---
[[⇦ Previous](1_23_exceptions_idx.md)]		[[Next  ⇨](1_25_stl_overview_idx.md)]		[[Index ⇧](index.md#1_24_error_as_values_idx.md)]
