<a name="1_17_rule_of_five_pt2-1"></a>
# RAII and The Rule of Five (Continued)

<a name="1_17_rule_of_five_pt2-1-1"></a>
## Move Semantics in C++  

- Optimizes performance by **transferring ownership** of resources **instead of copying them**. 
- Avoids expensive deep copies.

<a name="1_17_rule_of_five_pt2-1-1-1"></a>
###  Problem with Copy Semantics

- By default, C++ **copies objects** when passing them around, which can be costly.  

```cpp
class VectorND {
private:
    size_t n;
    double* arr;
public:
    VectorND(size_t dim) : n{ dim }, arr{ new double[dim] } {}

    // Copy constructor (Deep copy)
    VectorND(const VectorND& other) : n{ other.n }, arr{ new double[other.n] } {
        for (size_t i = 0; i < n; i++) arr[i] = other.arr[i];
    }

    ~VectorND() { delete[] arr; }
};
int main() {
    VectorND a(1000);  
    VectorND b = a;  // Creates a deep copy, allocating new memory 
}
```
⚠️ Allocates new memory and copies all elements of `a` to `b` even if `a` is no longer needed.


<a name="1_17_rule_of_five_pt2-1-2"></a>
## 4. Move Constructor

- The Rule of Five preconizes a **move constructor** to **"move"** an object around without creating copies.
- Instead of duplicating/cloning the state, we **transfer ownership** of the resources.

```cpp
VectorND { 
    //...
    // Move Constructor (Steals resources)
    VectorND(VectorND&& other) noexcept : n{ other.n }, arr{ other.arr } {
        other.n = 0;
        other.arr = nullptr; // Prevents double deletion
    }
    //...
};
int main() {
    VectorND a(1000);  
    VectorND b = std::move(a);  // Moves ownership from a to b 
}
```
- `b` takes ownership of `a`'s data.
- `a` becomes empty (`arr = nullptr`) and **ready for safe destruction**.
- No expensive deep copy!


<a name="1_17_rule_of_five_pt2-1-3"></a>
## 5. Move Assignment Operator

- In the Rule of Five, we need a **move assignment operator** to transfer ownership.

```cpp
VectorND {
    //...
    // Move Assignment Operator
    VectorND& operator=(VectorND&& other) noexcept {
        if (this == &other) return *this; // Self-assignment check

        delete[] arr;  // Free existing memory

        // Transfer ownership
        n = other.n;
        arr = other.arr;

        // Nullify source to prevent double delete
        other.n = 0;
        other.arr = nullptr;
        
        return *this;
    }
    //...
};
int main() {
    VectorND a(1000);
    VectorND b(500);
    b = std::move(a);  // Moves a into b
}
```

<a name="1_17_rule_of_five_pt2-1-4"></a>
## How Does the Compiler Decide Between Copying and Moving?

- The compiler uses **value categories** to determine whether to **copy** or **move** an object.

| **Category**  | **Definition**  | **Move Applied?** |
|--------------|----------------|----------------|
| **Lvalue**   | Named variable  | ❌ No move |
| **Rvalue**   | Temporary object  | ✅ Move constructor |

<a name="1_17_rule_of_five_pt2-1-4-1"></a>
### Rvalue References (`&&`) and Move Semantics

- If an object **has a name**, it's an **lvalue** → **Copy constructor** is used.
- If an object **has no name** (temporary object), it's an **rvalue** → **Move constructor** is used.

```cpp
VectorND a(1000);  
VectorND b = a;  // Uses copy constructor (a is an lvalue)
VectorND c = std::move(a);  // Uses move constructor (a is treated as an rvalue)
```

<a name="1_17_rule_of_five_pt2-1-4-2"></a>
### Rvalue from Function Return

- Move semantics should be used when returning large objects from functions

```cpp
VectorND createRandomVector(size_t n) {
    VectorND ret =  VectorND(n); 
    for (size_t i = 0; i < n; ret[i++] = rand());
    return ret; // ret about to be destroyed 
}
//...
VectorND v = createRandomVector(1000000);  // Move/RVO is applied
```

- The function returns an **unnamed temporary object** → **Rvalue**  
- The compiler applies **return value optimization (RVO)** or **move semantics**  
   - Before C++11: Copy constructor used  
   - C++11: Move Semantics
   - C++17: RVO (Copy ellision) mandatory


<a name="1_17_rule_of_five_pt2-1-5"></a>
## Rule of Five Summary

| Special Function  | Purpose  | When Called |
|------------------|----------|------------|
| **Copy Constructor** | Deep copy state/resources (copy `arr`) | `VectorND b = a;` |
| **Copy Assignment** | Deep copy, handles self-assignment | `b = a;` |
| **Move Constructor** | Transfers ownership (steals resource) | `VectorND b = std::move(a);` |
| **Move Assignment** | Transfers ownership, cleans up old | `b = std::move(a);` |
| **Destructor** | Cleans up memory (`delete[] arr;`) | When object goes out of scope |



---
[[⇦ Previous](1_16_rule_of_five_idx.md)]		[[Next  ⇨](1_18_smart_pointers_idx.md)]		[[Index ⇧](index.md#1_17_rule_of_five_pt2_idx.md)]
