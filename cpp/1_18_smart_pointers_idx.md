<a name="1_18_smart_pointers-1"></a>
# Smart Pointers (`std::unique_ptr` & `std::shared_ptr`) 

- Traditional C++ requires manual `new` and `delete` leading to:  
    - Memory leaks (forgetting to `delete`)  
    - Dangling pointers (accessing after deletion)  
    - Exception safety issues  
- Modern C++ introduces **smart pointers** (`std::unique_ptr` and `std::shared_ptr`) to **automatically** manage dynamic memory safely, following the RAII principle. 
- Eliminates/simplifies manual memory management and prevents memory leaks.

<a name="1_18_smart_pointers-1-1"></a>
## `std::unique_ptr` – Exclusive Ownership  

- Owns a resource exclusively (no copies allowed).  
- Automatically deletes the resource when it goes out of scope.  
- Follows the Rule of Five:  
  - No copy constructor or copy assignment  
  - Move constructor & move assignment  

```cpp
#include <iostream>
#include <memory>

class VectorND {
public:
    VectorND(size_t dim) { std::cout << "VectorND created\n"; }
    ~VectorND() { std::cout << "VectorND destroyed\n"; }
};

int main() {
    std::unique_ptr<VectorND> vec1 = std::make_unique<VectorND>(1000);
    
    // std::unique_ptr cannot be copied!
    // std::unique_ptr<VectorND> vec2 = vec1; // Error

    // But it can be moved:
    std::unique_ptr<VectorND> vec2 = std::move(vec1);  // Ownership transferred
    
    return 0;  // vec2 goes out of scope, VectorND is automatically deleted
}
```

<a name="1_18_smart_pointers-1-2"></a>
## `std::shared_ptr` – Shared Ownership  

- Allows multiple pointers to share ownership of the same resource.  
- Uses **reference counting** to track the number of owners.  
- Automatically deletes the resource when the last owner is destroyed.  

```cpp
#include <iostream>
#include <memory>

class VectorND {
public:
    VectorND(size_t dim) { std::cout << "VectorND created\n"; }
    ~VectorND() { std::cout << "VectorND destroyed\n"; }
};

int main() {
    std::shared_ptr<VectorND> vec1 = std::make_shared<VectorND>(1000);
    {
        std::shared_ptr<VectorND> vec2 = vec1;  //  Shared ownership
        std::cout << "Reference count: " << vec1.use_count() << "\n";  // 2
    }  
    // vec2 goes out of scope, but vec1 still exists
    std::cout << "Reference count: " << vec1.use_count() << "\n";  // 1

    return 0;  // vec1 is destroyed, resource is deallocated 
}
```

<a name="1_18_smart_pointers-1-3"></a>
## Key Differences Between `std::unique_ptr` and `std::shared_ptr`

| Feature            | `std::unique_ptr` | `std::shared_ptr` |
|-------------------|------------------|------------------|
| Ownership        | **Exclusive** (only one owner) | **Shared** (multiple owners) |
| Copyable?        | ❌ **No** (only movable) | ✅ **Yes** (increments ref count) |
| Moveable?        | ✅ **Yes** | ✅ **Yes** |
| Reference Counting? | ❌ **No** | ✅ **Yes** (deletes when ref count reaches 0) |
| Performance | ✅ **Fastest** (no ref counting overhead) | ❌ **Slightly slower** (ref counting) |


<a name="1_18_smart_pointers-1-4"></a>
## Smart Pointers and the Rule of Five  

- Smart pointers may eliminate the need for manual Rule of Five implementations:
    - No need for custom destructors (handled by smart pointers)  
    - No need for copy/move constructors (ownership is managed automatically)  

<a name="1_18_smart_pointers-1-4-1"></a>
### Without Smart Pointers:

```cpp
class VectorND {
private:
    size_t n;
    double* arr;
public:
    VectorND(size_t dim) : n{ dim }, arr{ new double[dim] } {}

    // Rule of Five
    ~VectorND() { delete[] arr; }  // Destructor 
    VectorND(const VectorND& other);  // Copy Constructor (Deep Copy)
    VectorND& operator=(const VectorND& other);  // Copy Assignment 
    VectorND(VectorND&& other) noexcept;  // Move Constructor 
    VectorND& operator=(VectorND&& other) noexcept;  // Move Assignment 
};
```

<a name="1_18_smart_pointers-1-4-2"></a>
### With `std::unique_ptr`:

```cpp
class VectorND {
private:
    size_t n;
    std::unique_ptr<double[]> arr;  // Smart pointer manages memory
public:
    VectorND(size_t dim) : n{ dim }, arr{ std::make_unique<double[]>(dim) } {}
};
```
- No need for destructor  
- No need for copy/move constructors  
- Memory is automatically managed  

---
[[⇦ Previous](1_17_rule_of_five_pt2_idx.md)]		[[Next  ⇨](1_19_inheritance_idx.md)]		[[Index ⇧](index.md#1_18_smart_pointers_idx.md)]
