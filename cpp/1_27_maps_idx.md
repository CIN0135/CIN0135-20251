<a name="1_27_maps-1"></a>
# `std::map`  

- **Sorted associative container** that stores key-value pairs.
- Keys ordered using `<` (by default). 
- Implemented as a balanced binary search tree (usually Red-Black Tree), ensuring O(log n) worst-case insertions, deletions, and lookups.
- **Keys are unique**: If you insert a duplicate key, the value is updated.

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Insert elements
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Access elements
    std::cout << "Key 2: " << myMap[2] << std::endl;  // Output: "Two"
}
```

<a name="1_27_maps-1-1"></a>
## Iterating Over

<a name="1_27_maps-1-1-1"></a>
### Using a Range-Based Loop (C++11+)

```cpp
for (const auto& [key, value] : myMap) {
    std::cout << key << " => " << value << std::endl;
}
```
⚠️ Uses **structured bindings** for clean syntax.


<a name="1_27_maps-1-1-2"></a>
### Using an Iterator

```cpp
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
}
```

<a name="1_27_maps-1-1-3"></a>
### Reverse Iteration

```cpp
for (auto it = myMap.rbegin(); it != myMap.rend(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
}
```

<a name="1_27_maps-1-2"></a>
## Lookup


| **Method**         | **Behavior** |  **Exception on Missing Key?** |
|-----------------|----------|--------------------------|
| `operator[]` | Returns a reference to the value, if the key exists. Otherwise, inserts a new default-constructed value. |  No exception. Inserts and returns default value. |
| `find()` | Returns an iterator to the element if found; otherwise returns `map.end()`. Does not modify the map. | No exception. Returns `end()`. |
| `at()` | Returns a reference to the value, if the key exists. Otherwise, throws `std::out_of_range`. |  Throws `std::out_of_range`. |


```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};

    // operator[]
    myMap[3] = "Three"; // Inserts {3, "Three"} if key 3 doesn't exist

    // find()
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found: " << it->second << std::endl;
    }

    // at()
    try {
        std::cout << "Value at 2: " << myMap.at(2) << std::endl;
        std::cout << "Value at 4: " << myMap.at(4) << std::endl; // Throws std::out_of_range
    } catch (const std::out_of_range &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

<a name="1_27_maps-1-3"></a>
##  Using `std::map` with User-Defined Classes as Keys

- `std::map` requires a **sorting mechanism** for keys. 
- By default, it uses `operator<`, so you must define it for custom key types.

<a name="1_27_maps-1-3-1"></a>
### Using a Custom Class as a Key

```cpp
#include <iostream>
#include <map>

class Point {
public:
    int x, y;
    
    Point(int x, int y) : x{x}, y{y} {}

    // Define operator< for sorting
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

// Print function for Point
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

int main() {
    std::map<Point, std::string> pointMap;

    // Inserting values
    pointMap[{2, 3}] = "Point A";
    pointMap[{1, 4}] = "Point B";
    pointMap[{3, 1}] = "Point C";

    // Iterating over map
    for (const auto& [point, name] : pointMap) {
        std::cout << point << " => " << name << std::endl;
    }

    return 0;
}
```

<a name="1_27_maps-1-3-2"></a>
### Using a Custom Comparator

- If you don’t want or cannot modify the class, you can pass a comparator functor.

```cpp
struct PointComparator {
    bool operator()(const Point& p1, const Point& p2) const {
        return (p1.x + p1.y) < (p2.x + p2.y);  // Custom sort: sum of coordinates
    }
};

std::map<Point, std::string, PointComparator> pointMap;
```


<a name="1_27_maps-1-4"></a>
##  Using `std::map` with User-Defined Classes as Values

- Values don’t need comparison operators, but should be copyable and/or movable.

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) : name{std::move(name)}, age{age} {}

    void print() const {
        std::cout << name << " (Age: " << age << ")" << std::endl;
    }
};

int main() {
    std::map<int, Person> people;
    people.emplace(1, Person("Alice", 30));
    people.emplace(2, Person("Bob", 25));

    for (const auto& [id, person] : people) {
        std::cout << "ID " << id << ": ";
        person.print();
    }
}
```
⚠️ Use `emplace()` to construct `Person` in-place, avoiding unnecessary copies.


---
[[⇦ Previous](1_26_vector_idx.md)]		[[Next  ⇨](1_28_unordered_maps_idx.md)]		[[Index ⇧](index.md#1_27_maps_idx.md)]
