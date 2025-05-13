<a name="1_20_templates-1"></a>
# Templates and Generic Programming 

- Templates in C++ allow for **generic programming**, i.e. code that works with **any data type** while avoiding code duplication. 
- Two main kinds of templates:
    - Function templates
    - Class templates.

<a name="1_20_templates-1-1"></a>
##  Function Templates

- Allows writing a single function definition that can operate on different data types.

```cpp
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swapValues(x, y);  // Works with int

    double a = 1.2, b = 3.4;
    swapValues(a, b);  // Works with double

    return 0;
}
```
- The **`template <typename T>`** tells the compiler that `T` is a **placeholder** for a type.
- The compiler **instantiates** the template with actual types (`int`, `double`, etc.) at compile-time.

<a name="1_20_templates-1-1-1"></a>
### Function Template Overloading

- Templates can also be overloaded to specialize behavior for certain types.

```cpp
template <typename T>
void print(T value) {
    std::cout << "Generic: " << value << "\n";
}

// Overloaded template for `char*`
template <>
void print(char* value) {
    std::cout << "String specialization: \"" << value << "\"\n";
}
```

<a name="1_20_templates-1-2"></a>
## Class Templates

- Defines a **blueprint** for a class that works with multiple data types.

```cpp
template <typename T>
class Vector {
private:
    T* arr;
    size_t size;
public:
    Vector(size_t n) : size(n), arr(new T[n]) {}
    ~Vector() { delete[] arr; }

    T& operator[](size_t i) { return arr[i]; }
};

int main() {
    Vector<int> v1(10);  // A vector of integers
    Vector<double> v2(5); // A vector of doubles
}
```

⚠️ `Vector<int>` and `Vector<double>` are **separate types** generated from the template.


<a name="1_20_templates-1-3"></a>
## Template Instantiation & Specialization

- Templates are instantiated when a specific **type** is provided.

<a name="1_20_templates-1-3-1"></a>
### Full Specialization

- A template can be **fully specialized** to behave differently for a specific type.

```cpp
template <typename T>
class Example {
public:
    void show() { std::cout << "Generic version\n"; }
};

// Full specialization for `int`
template <>
class Example<int> {
public:
    void show() { std::cout << "Specialized for int\n"; }
};
```

<a name="1_20_templates-1-3-2"></a>
### Partial Specialization

- Allows modifying behavior for a **subset** of template parameters.

```cpp
template <typename T1, typename T2>
class Pair { };

// Specialization when both types are the same
template <typename T>
class Pair<T, T> { };
```

<a name="1_20_templates-1-4"></a>
## Variadic Templates (C++11)

- Variadic templates allow a **variable number of template parameters** using **`...` (ellipsis).**

```cpp
template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    if constexpr (sizeof...(args) > 0) print(args...); // compile-time check
}

int main() {
    print(1, 2.5, "Hello", 'C');
}
```
- `Args...` is a **parameter pack** that holds multiple types.
- `sizeof...(args)` checks the number of remaining arguments.


<a name="1_20_templates-1-5"></a>
## Non-Type Template Parameters

- Templates can accept non-type values (integers, pointers, etc.).

```cpp
template <size_t N>
class Buffer {
private:
    char data[N];
};
Buffer<1024> buf;  // Buffer with 1024 bytes
```

<a name="1_20_templates-1-5-1"></a>
### `auto` as a Non-Type Parameter (C++17)

```cpp
template <auto N>
void printValue() { std::cout << N << "\n"; }

printValue<42>();  // Prints 42
```

<a name="1_20_templates-1-6"></a>
## Template Aliases & Deduction

<a name="1_20_templates-1-6-1"></a>
### Using `using` for Template Aliases

```cpp
template <typename T>
using Vec = std::vector<T>;

Vec<int> v;  // Equivalent to std::vector<int>
```

<a name="1_20_templates-1-6-2"></a>
### Template Argument Deduction (C++17)

```cpp
template <typename T>
class Container {
public:
    Container(T) { }
};

// Before C++17:
Container<int> c1(42);

// C++17 Deduction:
Container c2(42);  // Automatically deduces `T = int`
```



---
[[⇦ Previous](1_19_inheritance_idx.md)]		[[Next  ⇨](1_21_templates_metaprogramming_idx.md)]		[[Index ⇧](index.md#1_20_templates_idx.md)]
