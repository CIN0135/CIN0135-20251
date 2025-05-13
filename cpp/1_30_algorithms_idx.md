<a name="1_30_algorithms-1"></a>
# Algorithms

- The STL provides a set of generic functions for manipulating data in standard containers. 
- These algorithms are highly optimized and work with **iterators**.


<a name="1_30_algorithms-1-1"></a>
## Core Concepts

<a name="1_30_algorithms-1-1-1"></a>
### Ranges and Iterators

- STL algorithms work on **ranges**, typically defined by **begin** and **end** iterators:
	- `begin()` – Iterator to the first element.
	- `end()` – Iterator one past the last element (**not included**).

```cpp
std::sort(v.begin(), v.end()); // Sorts elements from v.begin() to v.end()
```

- Using iterators allows STL algorithms to work with **any container type**.


<a name="1_30_algorithms-1-1-2"></a>
### Functors (Function Objects)

- A **functor** is a class that overloads `operator()`, allowing it to be used like a function.  
- Functors allow stateful or reusable comparison logic.
- They are useful for: 
	- custom comparators, 
	- filtering, or 
	- transformations.


<a name="1_30_algorithms-1-1-2-1"></a>
#### Example: Functor for Custom Sorting

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct CompareDescending {
    bool operator()(int a, int b) {
        return a > b;  // Sort in descending order
    }
};

int main() {
    std::vector<int> v = {5, 2, 8, 1};
    
    std::sort(v.begin(), v.end(), CompareDescending());
    
    for (int num : v) std::cout << num << " "; // Output: 8 5 2 1
}
```

<a name="1_30_algorithms-1-1-3"></a>
### Lambda Functions

- Lambda functions are a **concise way** to define inline functions. 
- They are commonly used as **custom comparators** or **predicates** in STL algorithms.

<a name="1_30_algorithms-1-1-3-1"></a>
#### Lambda Syntax

```cpp
[ captures ] (parameters) -> return_type { body }
```
- **Captures (`[]`)**: Captures variables from the surrounding scope.
- **Parameters (`()`)**: Function arguments.
- **Return Type (`->`)**: Optional, inferred if omitted.
- **Body (`{}`)**: Function logic.

<a name="1_30_algorithms-1-1-3-2"></a>
#### Example: Sorting with a Lambda

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1};
    
    std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    for (int num : v) std::cout << num << " "; // Output: 8 5 2 1
}
```

<a name="1_30_algorithms-1-1-4"></a>
###  Predicates (Boolean Functions)

- A **predicate** is a function (or lambda) that returns `true` or `false`
- Often used for searching or filtering.

<a name="1_30_algorithms-1-1-4-1"></a>
#### Example: Finding the First Odd Number with `std::find_if`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool isOdd(int x) { return x % 2 != 0; }

int main() {
    std::vector<int> v = {2, 4, 6, 7, 8};
    
    auto it = std::find_if(v.begin(), v.end(), isOdd);
    
    if (it != v.end()) std::cout << "First odd number: " << *it << std::endl;
}
```

<a name="1_30_algorithms-1-2"></a>
## Examples of STL Algorithms

1. **Non-modifying algorithms** – `std::find`, `std::count`, `std::all_of`
2. **Modifying algorithms** – `std::copy`, `std::transform`, `std::fill`
3. **Sorting algorithms** – `std::sort`, `std::stable_sort`
4. **Searching algorithms** – `std::binary_search`, `std::find_if`
5. **Numeric algorithms** – `std::accumulate`, `std::iota`
6. **Set operations** – `std::set_union`, `std::set_intersection`


<a name="1_30_algorithms-1-3"></a>
##  Commonly Used STL Algorithms

<a name="1_30_algorithms-1-3-1"></a>
### Finding Elements

- `std::find(begin, end, value)` searches for a `value` withing the `[begin, end)` range.
- `std::find_if(begin, end, predicate)` searches for an element satisfying a `predicate` withing the `[begin, end)` range.
- Returns an iterator to the first match, or `end()` if none found.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

template <int N>
bool multiple_of(int val) {
  return val % N == 0;
}

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    for ( auto it = std::find_if(v.begin(), v.end(), multiple_of<4>); 
          it < v.end(); it = std::find_if(++it, v.end(), multiple_of<4>) ) {
        std::cout << "Found multiple of four: " << *it << std::endl;
    }
}
```

<a name="1_30_algorithms-1-3-2"></a>
### Binary Search

- `std::binary_search(begin, end, value)` searches for a value in an **sorted** `[begin, end)` range.

```cpp
#include <algorithm>
#include <cassert>
#include <complex>
#include <iostream>
#include <vector>
 
int main()
{
    const auto haystack = {1, 3, 4, 5, 9};
 
    for (const auto needle : {1, 2, 3})
    {
        std::cout << "Searching for " << needle << '\n';
        if (std::binary_search(haystack.begin(), haystack.end(), needle))
            std::cout << "Found " << needle << '\n';
        else
            std::cout << "Not found!\n";
    }
}
```


<a name="1_30_algorithms-1-3-3"></a>
### Min/Max

- `std::min_element(begin, end [, comparator])` finds the minimum in the `[begin, end)` range.
- `std::max_element(begin, end [, comparator])` finds the maximum in the `[begin, end)` range.

```cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> v{3, 1, -14, 1, 5, 9, -14, 9};
    std::vector<int>::iterator result;
 
    result = std::min_element(v.begin(), v.end());
    std::cout << "Min element found at index "
              << std::distance(v.begin(), result)
              << " has value " << *result << '\n';
 
    result = std::max_element(v.begin(), v.end(), [](int a, int b)
    {
        return std::abs(a) < std::abs(b);
    });
    std::cout << "Absolute max element found at index "
              << std::distance(v.begin(), result)
              << " has value " << *result << '\n';
}
```

<a name="1_30_algorithms-1-3-4"></a>
### Counting Elements

- `std::count(begin, end, value)` counts occurrences of a value within the `[begin, end)` range.
- `std::count_if(begin, end, predicate)` counts the elements matching `predicate` within the `[begin, end)` range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 2, 3, 3, 3};

    int count = std::count(v.begin(), v.end(), 3);
    std::cout << "Count of 3: " << count << std::endl;
}
```

<a name="1_30_algorithms-1-3-5"></a>
### Checking a Condition

- `std::all_of(begin, end, predicate)` checks if all elements in the `[begin, end)` range satisfy a condition.
- `std::all_of`, `std::any_of`, and `std::none_of` work analogously.
- Useful for validating a collection of elements.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    bool allEven = std::all_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All are even: " << std::boolalpha << allEven << std::endl;
}
```

<a name="1_30_algorithms-1-3-6"></a>
### Transforming Elements

- `std::for_each(begin, end, unary_function)` applies a unary function (or functor, or lambda) to each element in the `[begin, end)` range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct Sum {
	int accumulator = 0;
	void operator()(int &n) { accumulator += n;}
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), [](int &x) { x *= 2; });
   
	Sum sum = std::for_each(nums.begin(), nums.end(), Sum());

    for (int num : nums) {
        std::cout << num << " ";
    }
	std::cout << "\nSum = " << sum.accumulator << std::endl;

    return 0;
}
```

- `std::transform(begin, end, output, function)` applies a function to each element in the `[begin, end)` range.
- Stores the results in an given `output` container.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> result(v.size());

    std::transform(v.begin(), v.end(), result.begin(), [](int x) { return x * 2; });

    for (int num : result) {
        std::cout << num << " ";
    }
}
```

<a name="1_30_algorithms-1-3-7"></a>
### Sorting a Container

- `std::sort(begin, end)` sorts the elements in the `[begin, end)` range in ascending order.
- `std::sort(begin, end, comparator)` sorts the elements in the `[begin, end)` range in custom order given by a comparator. 
	- e.g. `[](int a, int b) { return a > b; })` sorts in descending order.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 1, 4, 2, 8};
    
    std::sort(v.begin(), v.end()); // Ascending order

    for (int num : v) {
        std::cout << num << " ";
    }
}
```

<a name="1_30_algorithms-1-3-8"></a>
### Accumulating (Folding) Elements

- `std::accumulate(begin, end, initial_value)` computes `initial_value` + the sum of the values in the `[begin, end)` range.
- `std::accumulate(begin, end, initial_value, binary_operator)` same as above w.r.t to a custom binary operator.

```cpp
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
 
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int sum = std::accumulate(v.begin(), v.end(), 0);
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
 
    auto dash_fold = [](std::string a, int b)
    {
        return std::move(a) + '-' + std::to_string(b);
    };
 
    std::string s = std::accumulate(std::next(v.begin()), v.end(),
                                    std::to_string(v[0]), // start with first element
                                    dash_fold);
 
    // Right fold using reverse iterators
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                     std::to_string(v.back()), // start with last element
                                     dash_fold);
 
    std::cout << "sum: " << sum << '\n'
              << "product: " << product << '\n'
              << "dash-separated string: " << s << '\n'
              << "dash-separated string (right-folded): " << rs << '\n';
}
```


... and many, many more ...


<a name="1_30_algorithms-1-4"></a>
## See More

[STD Algorithms Library](https://en.cppreference.com/w/cpp/algorithm)

---
[[⇦ Previous](1_29_iterators_idx.md)]		[[Next  ⇨](1_31_threads_idx.md)]		[[Index ⇧](index.md#1_30_algorithms_idx.md)]
