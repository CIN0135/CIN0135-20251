<a name="1_16_rule_of_five-1"></a>
# RAII and the Rule of Five

<a name="1_16_rule_of_five-1-1"></a>
## RAII

- RAII (Resource Acquisition Is Initialization) is a design pattern in C++ that ensures **automatic resource management** using **constructors and destructors**. 
- The key idea is to acquire a resource (memory, file, lock, etc.) in a constructor and release it in the destructor, ensuring proper cleanup
- Without RAII, we risk resource leaks, especially when exceptions occur. 

Consider a generalization of previous `Vector2D` to multidimensional spaces.

```cpp
class VectorND {
private:
    size_t n;    // vector size
    double* arr; // heap-allocated values 
public:
    // Constructor (resource acquisition)
    VectorND(size_t dim, double defaultValue = 0) : n{ dim }, arr{ new double[dim] } {
        for (size_t i = 0; i < n; arr[i++] = defaultValue);
    }
    // Destructor (resource release)
    ~VectorND() { delete[] arr; } // Always cleans up!
};


void safeFunction() {
    VectorND v(1000000); // Memory is allocated safely
    throw std::runtime_error("Something went wrong!"); // Destructor still runs!
}
```
↪ Now, even if an exception is thrown, the destructor runs and cleans up memory automatically!


<a name="1_16_rule_of_five-1-2"></a>
## The Rule of Five

To fully implement RAII, a class should implement five special methods:

1. **Destructor** → Releases resource  
2. **Copy Constructor** → Creates a deep copy  
3. **Copy Assignment** → Ensures proper resource management  
4. **Move Constructor** → Enables efficient transfers  
5. **Move Assignment** → Prevents unnecessary copies  

<a name="1_16_rule_of_five-1-2-1"></a>
### 1. Destructor

- Ensures **automatic resource cleanup** when an object goes out of scope.
- See previous examples


<a name="1_16_rule_of_five-1-2-2"></a>
### 2. Copy Constructor (Cloning)

- Creates a **deep copy** of other instance to avoid shared ownership of resources.
- Prevents dangling references, double free and other issues

```cpp
// Copy constructor
class VectorND {
    // ...
    VectorND(const VectorND& other) :  n{ other.n }, arr{ new double[other.n] } {
        for (size_t i = 0; i < n; i++) arr[i] = other.arr[i];
    }
    // ...
};
int main() {
    VectorND a(3, 1.0);
    VectorND b = a;  // Calls copy constructor
}
```
⚠️ If not provided, the default copy constructor would **shallow copy** `arr`, causing **double deletion** when both objects are destroyed.


<a name="1_16_rule_of_five-1-2-3"></a>
### 3. Copy Assignment Operator

- Same rationale of Copy constructor for already existing objects
- Handles **self-assignment** safely.
- Deletes old memory before allocating a new copy.

```cpp
class VectorND {
    //...
    // Copy assignment
    VectorND& operator=(const VectorND& other) {
        if (this == &other) return *this; // Self-assignment check
        delete[] arr;  // Free existing resource
        n = other.n;
        arr = new double[n];  // Allocate new memory
        for (size_t i = 0; i < n; i++) arr[i] = other.arr[i];
        return *this;
    }
    //...
};
int main() {
    VectorND a(3, 1.0);
    VectorND b(3, 2.0);
    b = a;  // Calls copy assignment
}
```


(to be continued...)

---
[[⇦ Previous](1_15_references_idx.md)]		[[Next  ⇨](1_17_rule_of_five_pt2_idx.md)]		[[Index ⇧](index.md#1_16_rule_of_five_idx.md)]
