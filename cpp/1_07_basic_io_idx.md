<a name="1_07_basic_io-1"></a>
# Basic I/O


Standard streams of **iostream** library:

- **`std::cout`** → Standard output (console)
- **`std::cin`** → Standard input (keyboard)
- **`std::cerr`** → Standard error (unbuffered)
- **`std::clog`** → Standard log output (buffered)


<a name="1_07_basic_io-1-1"></a>
## Output with `std::cout`  

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

- `std::cout` → Standard output stream.
- `<<` → Insertion operator (outputs data).
- `"Hello, World!"` → The message to be printed.
- `std::endl` → Inserts a newline **and flushes the output buffer**.


<a name="1_07_basic_io-1-2"></a>
## Read input with `std::cin`  

```cpp
#include <iostream>

int main() {
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You are " << age << " years old.\n"; // does not flush the buffer
    return 0;
}
```

- `std::cin >> age;` → Reads an integer input from the user.
- If the input type does not match, `cin` enters an error state.

<a name="1_07_basic_io-1-2-1"></a>
### Handling invalid input  

```cpp
while(true) {
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (std::cin.fail() || age < 0) {
        std::cerr << "Invalid input!\n";
        continue;
    }
}
```

<a name="1_07_basic_io-1-3"></a>
##  Inputting Strings 

- By default, `std::cin` stops reading at the first space. 
- To read full lines, use `std::getline()`.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string  name;
    std::cout << "Enter your full name: ";
    std::cin.ignore(); // clear input buffer
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!\n";
    return 0;
}
```

<a name="1_07_basic_io-1-4"></a>
## Error Messages with `std::cerr`  

- `std::cerr` is used for error messages and is **not buffered** i.e. prints **immediately**.

```cpp
std::cerr << "Error: File not found!\n";
```


<a name="1_07_basic_io-1-5"></a>
## Logging with `std::clog`  

- `std::clog` is used for logging messages and is **buffered**, meaning output might be delayed.
- Similar to `std::cerr` but unbuffered.
- Usually redirected to whatever logging means

```cpp
std::clog << "Logging info: Application started...\n";
```

---
[[⇦ Previous](1_06_control_flow_idx.md)]		[[Next  ⇨](1_08_file_io_idx.md)]		[[Index ⇧](index.md#1_07_basic_io_idx.md)]
