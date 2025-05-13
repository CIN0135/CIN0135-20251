<a name="1_11_strings-1"></a>
# Strings  

In C++, strings can be handled in two main ways:  
1. **C-style strings** (null-terminated character arrays)  
2. **`std::string` class** (from the Standard Library)  


<a name="1_11_strings-1-1"></a>
## C-Style Strings (`char` Arrays)  

- Array of characters terminated by a null character (`\0`).
- **Fixed-size**, cannot grow dynamically.  

```cpp
#include <iostream>

int main() {
    char greeting[] = "Hello";  // Implicit null-termination
    std::cout << greeting << std::endl;
    
    char name[6] = {'A', 'l', 'i', 'c', 'e', '\0'};  // Manually terminated
    std::cout << name << std::endl;
}
```

<a name="1_11_strings-1-1-1"></a>
### Common Functions from `<cstring>`

```cpp
#include <iostream>
#include <cstring>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    std::cout << strlen(str1) << std::endl;      // Get string length
    std::cout << strcat(str1, str2) << std::endl; // Concatenate (unsafe!)
    std::cout << strcmp(str1, str2) << std::endl; // Compare two strings
}
```

⚠️  `strcat()` and `strcpy()` can cause buffer overflows!


<a name="1_11_strings-1-2"></a>
## `std::string` Class 

- The **`std::string`** class (from `<string>`) provides a safer and more convenient way to work with strings.
- Advantages over C-style strings:  
    - Automatic memory management** (dynamic size).  
    - Easy concatenation (`+`).  
    - Safer and more powerful functions.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s1 = "Hello";
    std::string s2 = "World";

    std::cout << s1 + " " + s2 << std::endl;  // Concatenation
    std::cout << s1.length() << std::endl;    // Get length
    std::cout << s1.substr(1, 3) << std::endl; // Extract substring
}
```

<a name="1_11_strings-1-2-1"></a>
### Common `std::string` Operations  

<a name="1_11_strings-1-2-1-1"></a>
#### Concatenation

```cpp
std::string first = "Hello, ";
std::string last = "World!";
std::string full = first + last;  // "Hello, World!"
```

<a name="1_11_strings-1-2-1-2"></a>
#### Getting Length

```cpp
std::string text = "Example";
std::cout << text.length();  // 7
```

<a name="1_11_strings-1-2-1-3"></a>
#### Accessing Characters

```cpp
std::string word = "Hello";
std::cout << word[1];  // 'e'
word[0] = 'J';         // Changes to "Jello"
```

<a name="1_11_strings-1-2-1-4"></a>
#### Comparing Strings

```cpp
std::string a = "apple", b = "banana";
if (a == b) std::cout << "Equal";
else std::cout << "Not equal";  // "Not equal"
```

<a name="1_11_strings-1-2-1-5"></a>
#### Substring Extraction

```cpp
std::string phrase = "C++ Programming";
std::string sub = phrase.substr(4, 11);  // "Programming"
```

<a name="1_11_strings-1-2-1-6"></a>
#### Finding a Substring

```cpp
std::string sentence = "Hello, world!";
size_t pos = sentence.find("world");  // Returns index 7
```


<a name="1_11_strings-1-3"></a>
## Converting Between C-Strings and `std::string`

<a name="1_11_strings-1-3-1"></a>
### C-style -> `std::string`

```cpp
char cstr[] = "C-style string";
std::string str = cstr;  // Implicit conversion
```

<a name="1_11_strings-1-3-2"></a>
### `std::string` -> C-style 

```cpp
std::string str = "C++ String";
const char* cstr = str.c_str();  // Converts to C-string
```

⚠️  `c_str()` returns a `const char*`, so do not modify it!


<a name="1_11_strings-1-4"></a>
## Input and Output with Strings  

<a name="1_11_strings-1-4-1"></a>
### Reading a Single Word

```cpp
std::string name;
std::cin >> name;  // Stops at first whitespace
```

<a name="1_11_strings-1-4-2"></a>
### Reading an Entire Line

```cpp
std::string sentence;
std::getline(std::cin, sentence);
```

---
[[⇦ Previous](1_10_arrays_idx.md)]		[[Next  ⇨](1_12_functions_idx.md)]		[[Index ⇧](index.md#1_11_strings_idx.md)]
