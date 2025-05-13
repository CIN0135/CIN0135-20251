<a name="1_29_iterators-1"></a>
# Iterators

<a name="1_29_iterators-1-1"></a>
## What are iterators for?

- Iterators provide a way to traverse and access elements in STL containers in a uniform manner. 
- They act as a bridge between algorithms and containers, allowing algorithms to operate on containers without needing to know the underlying implementation of the container.

<a name="1_29_iterators-1-2"></a>
## What is an Iterator?

- An iterator is an object that points to an element in a container. 
- Behaves like a pointer, providing the following operations:
	1. **Dereferencing**: Access the element the iterator points to (`*iterator`, `iterator->`).
	2. **Increment/Decrement**: Move to the next or previous element (`++iterator`, `--iterator`, `iterator++`, `iterator--`).
	3. **Comparison**: Check if two iterators point to the same element (`==`, `!=`).
	4. **Arithmetic**: Move forward or backward by a number of steps (`iterator + n`, `iterator - n`).

<a name="1_29_iterators-1-3"></a>
## Types of Iterators

1. **Input Iterators**:
    - Can read elements from a container.
    - Support single-pass traversal (can only move forward).
    - Example: Iterators for `std::istream`.

2. **Output Iterators**:
    - Can write elements to a container.
    - Support single-pass traversal (can only move forward).
    - Example: Iterators for `std::ostream`.

3. **Forward Iterators**:
    - Can read and write elements.
    - Support multi-pass traversal (can move forward multiple times).
    - Example: Iterators for `std::forward_list`.

4. **Bidirectional Iterators**:
   - Can move forward and backward.
   - Support multi-pass traversal.
   - Example: Iterators for `std::list`, `std::set`, `std::map`.

5. **Random Access Iterators**:
    - Can move forward and backward.
    - Support arithmetic operations (e.g., `+`, `-`, `[]`).
    - Support multi-pass traversal.
    - Example: Iterators for `std::vector`, `std::array`, `std::deque`.

6. **Contiguous Iterator** (C++20):
    - Like Random Access but guarantees contiguous memory (optimizing cache efficiency) 
    - Example: `std::array::iterator`, `std::span::iterator` 


<a name="1_29_iterators-1-4"></a>
## Common Iterator Operations

| Operation               | Description                                                                 |
|-------------------------|-----------------------------------------------------------------------------|
| `*iter`                 | Dereference the iterator to access the element it points to.                |
| `iter->member`          | Access a member of the element the iterator points to.                      |
| `++iter`                | Move the iterator to the next element.                                      |
| `--iter`                | Move the iterator to the previous element (bidirectional and random access).|
| `iter++`                | Return current position and move the iterator to the nexe element.          |
| `iter--`                | Return current position and move the iterator to the previous element (bidirectional and random access).|
| `iter + n`              | Move the iterator forward by `n` elements (random access only).             |
| `iter - n`              | Move the iterator backward by `n` elements (random access only).            |
| `iter1 == iter2`        | Check if two iterators point to the same element.                           |
| `iter1 != iter2`        | Check if two iterators point to different elements.                         |
| `iter[n]`               | Access the element `n` positions away from the iterator (random access only).|


<a name="1_29_iterators-1-5"></a>
## Using Iterators in STL Containers

- Every STL container provides iterators through the following member functions:
	- `begin()`: Returns an iterator to the first element.
	- `end()`: Returns an iterator to one past the last element (used as a sentinel).
	- `cbegin()`, `cend()`: Constant (read-only) iterators.
	- `rbegin()`, `rend()`: Reverse iterators (for traversing backward).
	- `crbegin()`, `crend()`: Constant reverse iterators.

<a name="1_29_iterators-1-5-1"></a>
### Example Traversing a `std::vector`

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Traverse using iterators
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    return 0;
}
```

Output:
```
1 2 3 4 5
```

<a name="1_29_iterators-1-6"></a>
## Iterator Invalidation

- Iterators can become invalid if the underlying container is modified in certain ways. For example:
	- Adding or removing elements from a `std::vector` can invalidate iterators.
	- Inserting into or erasing from a `std::map` may invalidate iterators pointing to the affected elements.
- Always be cautious when modifying containers while using iterators.


<a name="1_29_iterators-1-7"></a>
## Defining a Custom Iterator

- Defining iterators for your own container classes, enables them to work seamlessly with STL algorithms and range-based for loops. 
- A custom iterator must implement the required operations for its category (e.g., input, forward, bidirectional, or random access). 

1. **Define the Iterator Class**:
   - Create a class for your iterator.
   - Include the necessary member functions and operators based on the iterator category.

2. **Define the Required Operations**:
    - When defining a custom iterator, you must decide which category it belongs to. 
    - The category determines which operations are required:

    | Operation | Input | Output | Forward | Bidirectional | Random Access | Contiguous (C++20) |
    |-----------|------|--------|---------|--------------|---------------|---------------|
    | `*it` (dereference) | ✔ |  | ✔ | ✔ | ✔ | ✔ |
    | `it->member` (member access) | ✔ |  | ✔ | ✔ | ✔ | ✔ |
    | `++it` (prefix increment) | ✔ | ✔ | ✔ | ✔ | ✔ | ✔ |
    | `it++` (postfix increment) | ✔ | ✔ | ✔ | ✔ | ✔ | ✔ |
    | `--it` (decrement) |  |  |  | ✔ | ✔ | ✔ |
    | `it + n` (advancing) |  |  |  |  | ✔ | ✔ |
    | `it - n` (backward) |  |  |  |  | ✔ | ✔ |
    | `it1 - it2` (distance) |  |  |  |  | ✔ | ✔ |
    | `it[n]` (array-like access) |  |  |  |  | ✔ | ✔ |
    | `==`, `!=` (comparison) | ✔ |  | ✔ | ✔ | ✔ | ✔ |
    | `<`, `<=`, `>`, `>=` (ordering) |  |  |  |  | ✔ | ✔ |

3. **Define Iterator Traits**:
   - Specialize `std::iterator_traits` for your iterator to provide information about the iterator's properties (e.g., value type, difference type, etc.).
   - Necessary for full and optimized integration with STL algorithms.

4. **Integrate with Your Container**:
   - Provide `begin()` and `end()` methods in your container class to return iterators.


<a name="1_29_iterators-1-7-1"></a>
### Example: Custom Iterator for a Simple Array Container

Let's create a custom iterator for a simple array-based container.

<a name="1_29_iterators-1-7-1-1"></a>
#### Step 1: Define the Container
```cpp
#include <iostream>
#include <iterator> // For std::iterator_traits

template <typename T, size_t N>
class SimpleArray {
private:
    T data[N];

public:
    // Iterator class
    class Iterator {
    private:
        T* ptr;

    public:
        // Constructor
        explicit Iterator(T* p) : ptr(p) {}

        // Dereference operator
        T& operator*() const {
            return *ptr;
        }

        // Pre-increment operator
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        // Equality operator
        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        // Arithmetic operators (for random access)
        Iterator operator+(size_t n) const {
            return Iterator(ptr + n);
        }

        Iterator operator-(size_t n) const {
            return Iterator(ptr - n);
        }

        T& operator[](size_t n) const {
            return *(ptr + n);
        }
    };

    // Begin and end methods
    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + N);
    }

    // Access elements
    T& operator[](size_t index) {
        return data[index];
    }
};
```

<a name="1_29_iterators-1-7-1-2"></a>
#### Step 2: Define Iterator Traits

- To make your iterator compatible with STL algorithms, specialize `std::iterator_traits`:

```cpp
namespace std {
    template <typename T>
    struct iterator_traits<typename SimpleArray<T, 10>::Iterator> {
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;
    };
}
```

<a name="1_29_iterators-1-7-1-3"></a>
#### Step 3: Use the Custom Iterator

- Now you can use the custom iterator with your container:

```cpp
int main() {
    SimpleArray<int, 5> arr;

    // Fill the array
    for (size_t i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    // Traverse using custom iterator
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // Use STL algorithms
    auto it = std::find(arr.begin(), arr.end(), 30);
    if (it != arr.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    return 0;
}
```

Output:
```
0 10 20 30 40
Found: 30
```

<a name="1_29_iterators-1-8"></a>
## See More

[Iterator traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits)

---
[[⇦ Previous](1_28_unordered_maps_idx.md)]		[[Next  ⇨](1_30_algorithms_idx.md)]		[[Index ⇧](index.md#1_29_iterators_idx.md)]
