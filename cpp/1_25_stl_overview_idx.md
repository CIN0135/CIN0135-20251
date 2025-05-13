<a name="1_25_stl_overview-1"></a>
# C++ Standard Template Library (STL) Overview

- The **Standard Template Library (STL)** provides generic and reusable divided into:
    1. **Containers** – Data structures to store elements.
    2. **Iterators** – Provide a way to traverse containers.
    3. **Algorithms** – Perform operations like searching, sorting, and modifying data.
    4. **Function Objects (Functors) & Utilities** – Enable custom behavior in algorithms.
- It follows a template-based approach, enabling efficient and type-safe operations.


<a name="1_25_stl_overview-1-1"></a>
## 1. Containers

- Used to store collections of objects. 

<a name="1_25_stl_overview-1-1-1"></a>
### Sequence Containers (Ordered Collections)

- [`std::vector<T>`](https://en.cppreference.com/w/cpp/container/vector) – Dynamic array with fast random access.
- [`std::deque<T>`](https://en.cppreference.com/w/cpp/container/deque) – Double-ended queue for fast insert/delete at both ends.
- [`std::list<T>`](https://en.cppreference.com/w/cpp/container/list)– Doubly linked list (efficient insert/remove anywhere).
- [`std::forward_list<T>`](https://en.cppreference.com/w/cpp/container/forward_list)– Singly linked list (lighter, but forward-only).
- [`std::array<T, N>`](https://en.cppreference.com/w/cpp/container/array) – Fixed-size array (C++11).

**Example: Using `std::vector`**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    numbers.push_back(6); // Add element at the end

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```

<a name="1_25_stl_overview-1-1-2"></a>
### Associative Containers (Sorted Key-Value or Set-Based)

- [`std::set<T>`](https://en.cppreference.com/w/cpp/container/set) – Unique, sorted elements.
- [`std::multiset<T>`](https://en.cppreference.com/w/cpp/container/multiset) – Sorted, but allows duplicate elements.
- [`std::map<K, V>`](https://en.cppreference.com/w/cpp/container/map) – Key-value pairs, sorted by key.
- [`std::multimap<K, V>`](https://en.cppreference.com/w/cpp/container/multimap) – Like `map`, but allows duplicate keys.

**Example: Using `std::map`**

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 85}};
    scores["Charlie"] = 95; // Insert new key-value pair

    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << '\n';
    }
}
```

<a name="1_25_stl_overview-1-1-3"></a>
### Unordered Containers (Hash-Based, Fast Lookups)

- [`std::unordered_set<T>`](https://en.cppreference.com/w/cpp/container/unordered_set) – Unique elements, no order.
- [`std::unordered_map<K, V>`](https://en.cppreference.com/w/cpp/container/unordered_map) – Key-value pairs, no order.
- [`std::unordered_multiset<T>`](https://en.cppreference.com/w/cpp/container/unordered_multiset) – Allows duplicates, no order.
- [`std::unordered_multimap<K, V>`](https://en.cppreference.com/w/cpp/container/unordered_multimap) – Key-value pairs, allows duplicate keys.

**Example: Using `std::unordered_set`**

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> numbers = {4, 2, 8, 1, 3};

    numbers.insert(5);
    numbers.erase(2);

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```

<a name="1_25_stl_overview-1-2"></a>
## 2. Iterators

- Provide a generic way to traverse through elements in containers.

<a name="1_25_stl_overview-1-2-1"></a>
### Types of Iterators

1. **Input Iterator** → Read-only, forward traversal (`std::istream_iterator`).
2. **Output Iterator** → Write-only (`std::ostream_iterator`).
3. **Forward Iterator** → Read/write, single pass (`std::forward_list`).
4. **Bidirectional Iterator** → Can move forward/backward (`std::list`, `std::map`).
5. **Random Access Iterator** → Fast indexing (`std::vector`, `std::deque`).

**Example: Using Iterators**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
}
```

**Example: Range-Based For Loop (C++11)**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30};

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```


<a name="1_25_stl_overview-1-3"></a>
## 3. Algorithms

The **`<algorithm>`** header provides many common operations, such as:
- **Sorting:** `std::sort(begin, end)`
- **Searching:** `std::binary_search(begin, end, value)`
- **Min/Max:** `std::min_element(begin, end)`, `std::max_element(begin, end)`
- **Counting:** `std::count(begin, end, value)`
- **Modifying:** `std::reverse(begin, end)`, `std::transform(begin, end, output, func)`

**Example: Sorting a Vector**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 3, 8, 1, 2};

    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```

<a name="1_25_stl_overview-1-4"></a>
## 4. Function Objects (Functors) & Utilities

- **Function Objects (Functors):** Custom callable objects that can be used with STL algorithms.
- **Lambdas (C++11+):** Anonymous functions for inline behavior.
- **Pair (`std::pair<T1, T2>`):** Stores two values together.
- **Tuple (`std::tuple<T1, T2, T3>`):** Stores multiple values.

**Example: Using a Functor**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct MultiplyByTwo {
    int operator()(int x) const { return x * 2; }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), MultiplyByTwo());

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```

**Example: Using a Lambda (C++11)**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), 
                   [](int x) { return x * 2; });

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
```

---
[[⇦ Previous](1_24_error_as_values_idx.md)]		[[Next  ⇨](1_26_vector_idx.md)]		[[Index ⇧](index.md#1_25_stl_overview_idx.md)]
