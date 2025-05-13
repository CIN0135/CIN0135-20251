<a name="1_12_functions-1"></a>
# Functions  

- A **function** in C++ is a block of reusable code that performs a specific task. 
- Functions improve:
    - code organization
    - modularity
    - reusability.


<a name="1_12_functions-1-1"></a>
## Function Prototypes and Definitions  

<a name="1_12_functions-1-1-1"></a>
### Function Prototype

- Function **declaration** specifying:
    - The **return type**  
    - The **function name**  
    - The **parameter list**  
- Allows writing code calling the function before defining it
- **WHAT** the function does


<a name="1_12_functions-1-1-2"></a>
### Function Defintion

- Actual implementation of intended behaviour according to the declaration
- **HOW** the function does 


```cpp
#include <iostream>

// Function prototype (declaration)
int add(int a, int b);

int main() {
    std::cout << add(3, 4);  // Function call
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```


<a name="1_12_functions-1-2"></a>
## Function Overloading  

- Multiple functions **with the same name but different parameter lists** 
- Return type **alone** cannot differentiate overloaded functions (parameter lists must be different)
- Which version is used decided at runtime depending on the arguments

```cpp
#include <iostream>

// Overloaded functions
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }
int multiply(int a, int b, int c) { return a * b * c; }

int main() {
    std::cout << multiply(3, 4) << std::endl;       // Calls multiply(int, int)
    std::cout << multiply(2.5, 3.0) << std::endl;   // Calls multiply(double, double)
    std::cout << multiply(2, 3, 4) << std::endl;    // Calls multiply(int, int, int)
}
```

<a name="1_12_functions-1-3"></a>
## Default Arguments  

- A **default argument** is a value assigned to a function parameter **if no argument is provided** during the function call.
- Default arguments **must be specified in the function prototype or definition**.  
- If a function is **overloaded**, the version without default arguments is preferred.

```cpp
#include <iostream>

// Function with default argument
void greet(std::string name = "Guest") {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main() {
    greet();            // Uses default: "Hello, Guest!"
    greet("Alice");     // Overrides default: "Hello, Alice!"
}
```


<a name="1_12_functions-1-3-1"></a>
### Multiple Default Arguments

- **Must be defined from right to left** (cannot skip middle arguments).  

```cpp
void displayInfo(std::string name, int age = 25, std::string city = "Unknown") {
    std::cout << name << ", " << age << " years old, from " << city << std::endl;
}

displayInfo("John");                // Uses default age and city
displayInfo("Emily", 30);            // Uses default city
displayInfo("Alex", 40, "New York"); // Overrides all defaults
```


<a name="1_12_functions-1-4"></a>
## Inline Functions  

- An **inline function** suggests to the compiler to replace the function call with its actual code **to reduce function call overhead**.  
- Useful for small, frequently used functions.

```cpp
#include <iostream>

// Inline function
inline int square(int x) {
    return x * x;
}

int main() {
    std::cout << square(5);  // Compiler may replace with "5 * 5"
}
```

⚠️  **Note:**
- The **compiler ultimately decides** whether to inline the function.  
- Inlining large functions increases code size (can harm performance due to cache misses).  
- Avoid inlining recursive or complex functions.

---
[[⇦ Previous](1_11_strings_idx.md)]		[[Next  ⇨](1_13_namespaces_idx.md)]		[[Index ⇧](index.md#1_12_functions_idx.md)]
