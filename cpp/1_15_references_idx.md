<a name="1_15_references-1"></a>
# References (`&`)

- A **reference** in C++ is an alias for an existing variable. 
- It provides a way to access the same object using a different name, **without creating a copy**.  

<a name="1_15_references-1-1"></a>
## Syntax of References

```cpp
int a = 10;
int& ref = a;  // 'ref' is a reference to 'a'
```
- `ref` is not a new variable but another name for `a`.
- Any change to `ref` affects `a`, and vice versa.

```cpp
#include <iostream>
int main() {
    int x = 5;
    int& y = x; // y is a reference to x

    std::cout << "x: " << x << ", y: " << y << std::endl; 
    y = 10; // Modifies x too

    std::cout << "x: " << x << ", y: " << y << std::endl;
}
```
<a name="1_15_references-1-1-1"></a>
### Output
```
x: 5, y: 5
x: 10, y: 10
```

<a name="1_15_references-1-2"></a>
## Properties of References

- **Must be initialized at declaration**  
  ```cpp
  int& ref;  //  ERROR: References must be initialized
  ```
- **Cannot be reassigned**  
  ```cpp
  int a = 10, b = 20;
  int& ref = a;
  ref = b;  //  This does NOT change ref to reference 'b', it just assigns 'b' to 'a'
  ```
- **Cannot be null**  
  ```cpp
  int& ref = nullptr; // ERROR: References must refer to a valid object
  ```
- **Does not consume extra memory** (unlike pointers)
- Faster than pointers (do not require dereferencing)
- Safer than pointers


<a name="1_15_references-1-3"></a>
## Using References in Functions

<a name="1_15_references-1-3-1"></a>
### Pass-by-Reference (Avoids Copying)

- Faster than passing by value (no copy).

```cpp
void scale(Vector2D& v, double factor) {
    v.scale(factor);  // Modifies the original object
}
```

<a name="1_15_references-1-3-2"></a>
### Returning a Reference

```cpp
int& getMax(int& a, int& b) {
    return (a > b) ? a : b;
}
```

⚠️ Do not return references to local variables!


<a name="1_15_references-1-4"></a>
## Unmutable `const` References

- Used for **read-only access**.

```cpp
void print(const Vector2D& v) { // Cannot modify v
    std::cout << v.X() << ", " << v.Y() << std::endl;
}
```

-  Works with Temporary Values

```cpp
const int& ref = 5;  // OK (compiles)
int& ref2 = 5;  // ERROR: Cannot bind non-const reference to a temporary
```

<a name="1_15_references-1-5"></a>
## When to Use References?

- When passing large objects to functions (`const&` for efficiency).  
- When returning values from functions (to avoid copying).  
- When you want to ensure the reference is **never null**.  

---
[[⇦ Previous](1_14_OOP_classes_idx.md)]		[[Next  ⇨](1_16_rule_of_five_idx.md)]		[[Index ⇧](index.md#1_15_references_idx.md)]
