<a name="1_28_unordered_maps-1"></a>
# `std::unordered_map` (vs. `std::map`)  

- `std::unordered_map` is a **hash table-based associative container**
- Creation/lookup/insertion/deletion similar to `std::map` but with key differences:


| Feature | `std::map` | `std::unordered_map` |
|---------|-----------|----------------------|
| **Implementation** | **Balanced BST (Red-Black Tree)** | **Hash Table** |
| **Ordering** | **Keys are sorted** | **No specific order** |
| **Lookup Complexity** | **O(log n)** | **O(1) average, O(n) worst case** |
| **Insertion Complexity** | **O(log n)** | **O(1) average, O(n) worst case** |
| **Memory Usage** | **Less overhead** | **More due to hash table buckets** |
| **Best for** | When **order matters** | When **fast lookups** matter |


<a name="1_28_unordered_maps-1-1"></a>
## Using `std::unordered_map` with Custom Classes  

- To use a custom class as a key in `std::unordered_map`, we must provide: 
	- "Equals" comparison operator (`operator==()`). 
	- A hash function because it uses hashing instead of comparisons. This can be done either:
		- By specializing the `std::hash` functor.
		- By providing a custom Hash functor.

```cpp
#include <iostream>
#include <unordered_map>
#include <functional>

struct Point {
    int x, y;
    bool operator==(const Point& other) const { // Required for unordered_map
        return x == other.x && y == other.y;
    }
};

// Specializing std::hash 
namespace std {
    template <>
    struct hash<Point> {
        std::size_t operator()(const Point& p) const {
            // Combine the hash values of the members
        	return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
        }
    };
}

// Custom hash functor
struct PointHash {
    std::size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

int main() {
    std::unordered_map<Point, std::string, PointHash> pointMap;

	pointMap[{1, 2}] = "A";
    pointMap[{3, 4}] = "B";

    std::cout << "Point (1,2): " << pointMap[{1, 2}] << std::endl;

	std::unordered_map<Point, std::string> pointMap2;

	pointMap2[{5, 6}] = "C";
    pointMap2[{7, 8}] = "D";

    std::cout << "Point (7,8): " << pointMap2[{7, 8}] << std::endl;
}
```

<a name="1_28_unordered_maps-1-1-1"></a>
### ⚠️ Key Rule: Consistency Between `==` and Hash Function

- When using a custom class as a key in an `std::unordered_map`, there is a critical **interdependency** between them:j
**If two objects are considered equal, their hash values ️must be the same.** 

```
If obj1 == obj2, then hash(obj1) == hash(obj2)
```

- This is because `std::unordered_map` relies on the hash value to group keys into buckets. If two keys are equal but produce different hash values, the map will not work correctly, leading to undefined behavior or logical errors.

---
[[⇦ Previous](1_27_maps_idx.md)]		[[Next  ⇨](1_29_iterators_idx.md)]		[[Index ⇧](index.md#1_28_unordered_maps_idx.md)]
