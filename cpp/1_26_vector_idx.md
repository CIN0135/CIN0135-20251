<a name="1_26_vector-1"></a>
# `std::vector` 

- **Dynamic Array** with:
    - Contiguous memory → Elements are stored like an array, ensuring fast access.
    - Random access (O(1) complexity) → Supports direct element access via indexing.
    - Automatic resizing → Expands automatically when needed.
    - Efficient insertions/deletions → `push_back()` is amortized O(1) but insertions/removals in the middle are O(n) worst-case.
- Supports iterators → Works well with STL algorithms.
- One of the most commonly used containers in STL.

<a name="1_26_vector-1-1"></a>
## Creation/Destruction 

- If a vector holds objects, its destruction triggers the destruction of each element.

```cpp
#include <vector>
#include <iostream>
#include <exception>

using namespace std;

class Foo {
public:
    Foo(int i): i{i} {}
    ~Foo() {
        cout << "destructing " << *this << endl;
    }
    friend ostream& operator<<(ostream &os, const Foo& foo) {
        os << "Foo{" << foo.i <<"}";
        return os;
    }
private:
    int i;
};

int main() {
  vector<Foo> foos = {1,2,3};
  
  for (auto &f: foos) {
    cout << f << endl; 
  }
  
  // The three Foo instances of foos are automatically destructed
} 
```

- If a vector holds pointers to objects, its destruction **does not** trigger the destruction of individual elements. They must be manually destructed. 

```cpp
int main() {
    vector<Foo*> pfoos;
    pfoos.push_back(new Foo(4));
    pfoos.push_back(new Foo(5));
    pfoos.push_back(new Foo(6));
    for (auto &pf: pfoos) {
        cout << *pf << endl; 
    }
    // clear individual elements
    for (auto &pf: pfoos) {
        delete pf;
    }
    pfoos.clear();
    // 
}
```

- Objects held by smart pointers are destructed with the vector when no other reference remains.

```cpp
int main() {
    auto nine = make_shared<Foo>(9);
    if (true) {
        vector<shared_ptr<Foo>> spfoos;
        spfoos.push_back(make_shared<Foo>(7));
        spfoos.push_back(make_shared<Foo>(8));
        spfoos.push_back(nine); 
    } // first two objects destroyed with the vector
    cout << "------" << endl;
    cout << *nine << " lives! " << endl;
}
````

<a name="1_26_vector-1-2"></a>
## Memory Management and Capacity

| **Function** | **Description** |
|--------------|----------------|
| `size()` | Number of elements in the vector |
| `capacity()` | Allocated storage size (≥ `size()`) |
| `empty()` | Returns `true` if vector is empty |
| `reserve(n)` | Pre-allocates memory for at least `n` elements |
| `shrink_to_fit()` | Reduces capacity to match size |

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.reserve(10); // Pre-allocate memory
    
    std::cout << "Size: " << v.size() << '\n'; // Prints Size: 0
    std::cout << "Capacity: " << v.capacity() << '\n'; // Prints Capacity: 10

    for (int i = 0; i < 5; ++i) v.push_back(i);

    std::cout << "Size: " << v.size() << '\n'; // Prints Size: 5
    std::cout << "Capacity: " << v.capacity() << '\n'; // Prints Capacity: 10

    v.shrink_to_fit();
    
    std::cout << "Size: " << v.size() << '\n'; // Prints Size: 5
    std::cout << "Capacity: " << v.capacity() << '\n'; // Prints Capacity: 5 
}
```

<a name="1_26_vector-1-3"></a>
##  Accessing Elements

| **Operation** | **Description** |
|--------------|----------------|
| `v[i]`       |  Access element at index `i` (O(1) w/o bounds check) |
| `v.at(i)` | Access element at index `i` (O(1) w/ bounds check) |
| `front()` | Returns the first element (unsafe) |
| `back()` | Returns the last element (unsafe) |

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};

    std::cout << v[1] << '\n';    // Direct access (unsafe)
    std::cout << v.at(1) << '\n'; // Bounds-checked access (safe)
}
```

<a name="1_26_vector-1-4"></a>
## Adding and Removing Elements

| **Operation** | **Description** |
|--------------|----------------|
| `push_back(value)` | Adds an element at the end (O(1) amortized) |
| `pop_back()` | Removes the last element (O(1)) |
| `insert(pos, value)` | Inserts an element at a specific position (O(n)) |
| `erase(pos)` | Removes an element at a specific position (O(n)) |
| `clear()` | Removes all elements |

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};

    v.insert(v.begin() + 1, 15); // Insert 15 at index 1
    v.erase(v.begin());          // Remove first element

    for (int num : v) std::cout << num << " ";
}
```

<a name="1_26_vector-1-4-1"></a>
### Adding with `std::vector::emplace`  

- `std::vector::push_back` first creates an object and then copies/moves it.
- `std::vector::emplace` constructs an element directly **in place** inside a `std::vector`. 

```cpp
vec.emplace(position, args...);
    - `position` → Iterator where the element should be inserted.
    - `args...` → Arguments forwarded to the constructor of the element type.

vec.emplace_back, args...);
    - equivalent to vec.emplace(vec.end(), args...);
```

```cpp
#include <iostream>
#include <vector>

class Foo {
public:
    int x;
    Foo(int x) : x{x} { std::cout << "Constructing Foo(" << x << ")\n"; }
    // ...
};

int main() {
    std::vector<Foo> vec;

    Foo f(10);      // Constructs Foo
    vec.push_back(f); // Copies Foo into vector
    vec.push_back(Foo(20)); // Creates temp Foo, then moves it

    vec.emplace_back(30);              // Construct directly in vector
    vec.emplace(vec.begin() + 1, 25);  // No extra temporary object
    return 0;
}
```


<a name="1_26_vector-1-5"></a>
## Traversing a `vector`

<a name="1_26_vector-1-5-1"></a>
### Using an Iterator

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
}
```

<a name="1_26_vector-1-5-2"></a>
### Using Range-Based Loop (C++11)

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};

    for (int num : v) {
        std::cout << num << " ";
    }
}
```

<a name="1_26_vector-1-6"></a>
## Moving and Swapping

- **Move Semantics (`std::move()`)** avoids expensive deep copies.
- **`swap()`** efficiently exchanges two vectors.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1); // v1 is now empty

    std::cout << "v2 size: " << v2.size() << '\n';
}
```

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};

    a.swap(b);

    for (int num : a) std::cout << num << " "; // Outputs: 4 5 6
}
```

---
[[⇦ Previous](1_25_stl_overview_idx.md)]		[[Next  ⇨](1_27_maps_idx.md)]		[[Index ⇧](index.md#1_26_vector_idx.md)]
