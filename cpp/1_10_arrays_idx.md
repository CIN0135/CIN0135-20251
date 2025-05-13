<a name="1_10_arrays-1"></a>
# Arrays

- **Fixed-size** (*static*) collection of elements of the **same type** (*homogeneous*).
- Stored in a block of contiguous memory locations -> efficient indexing and traversal.

<a name="1_10_arrays-1-1"></a>
## Basic Declaration

```cpp
int numbers[5];  // An array of 5 integers (uninitialized)
```

- The size **must be known at compile-time** (for regular arrays).  
- Elements are stored **contiguously in memory**.

<a name="1_10_arrays-1-2"></a>
## Initialization at Declaration

```cpp
int numbers[5] = {1, 2, 3, 4, 5};  // Fully initialized array
int zeros[5] = {};                 // All elements set to 0 (only for global/static arrays)
int partial[5] = {1, 2};           // First 2 elements set, others default to 0
int numbers[] = {1, 2, 3, 4, 5};   // Array of size 5 (compiler infers size)
```

<a name="1_10_arrays-1-2-1"></a>
### Default Values

- Local arrays: **Uninitialized (garbage values)**
- Global/static arrays: **Zero-initialized**


<a name="1_10_arrays-1-3"></a>
## Accessing and Modifying Elements  

<a name="1_10_arrays-1-3-1"></a>
### Indexing (Zero-Based)

```cpp
int arr[3] = {10, 20, 30};
std::cout << arr[0];  // Prints 10
std::cout << arr[1];  // Prints 20
```

<a name="1_10_arrays-1-3-2"></a>
### Modifying elements:

```cpp
arr[2] = 50;  // Now arr = {10, 20, 50}
```

<a name="1_10_arrays-1-3-3"></a>
### ⚠️  Out-of-Bounds Access  

- C++ **does not check array bounds**!

```cpp
std::cout << arr[10];  // Undefined behavior!
```


<a name="1_10_arrays-1-4"></a>
## Iteration  

<a name="1_10_arrays-1-4-1"></a>
### For Loop

```cpp
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);  // Compute array size

for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
}
```

<a name="1_10_arrays-1-4-2"></a>
### Range-Based For Loop (C++11)

```cpp
for (int num : arr) {
    std::cout << num << " ";
}
```

- **Safer** than a regular for-loop.


<a name="1_10_arrays-1-5"></a>
## Multidimensional Arrays  

<a name="1_10_arrays-1-5-1"></a>
### 2D Array (Matrix)

```cpp
int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
}
```

<a name="1_10_arrays-1-6"></a>
## Arrays and Pointers  

<a name="1_10_arrays-1-6-1"></a>
### Arrays Decay into Pointers

- An array **name** is a pointer to the first element

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;  // Equivalent to &arr[0]
std::cout << *ptr;  // Prints 10
```

<a name="1_10_arrays-1-6-2"></a>
### Pointer arithmetic

```cpp
std::cout << *(ptr + 1);  // Prints 20 (equivalent to arr[1])
```

<a name="1_10_arrays-1-6-3"></a>
### Dynamically allocated arrays 

* Pointers are used for dynamically-allocated arrays

```cpp
unsigned int size;
std::cout << "Enter array size: ";
std::cin >> size;
int *sqarr = new int[size]; // Array size only known at runtime
for (unsigned int i = 0; i < size; i++) {
    sqarr[i] = i * i;
}
delete[] sqarr; // free array memory
```

---
[[⇦ Previous](1_09_binary_file_io_idx.md)]		[[Next  ⇨](1_11_strings_idx.md)]		[[Index ⇧](index.md#1_10_arrays_idx.md)]
