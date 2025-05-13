<a name="1_08_file_io-1"></a>
# File I/O 

- File handling using the `<fstream>` library includes three main classes:  
	- `std::ifstream` (input file stream) → for reading files  
	- `std::ofstream` (output file stream) → for writing files  
	- `std::fstream` (file stream) → for both reading and writing  
- For text files, similar to standard I/O streams.

<a name="1_08_file_io-1-1"></a>
## Writing to a File  

```cpp
#include <iostream>
#include <fstream> // Include file stream library

int main() {
    std::ofstream outFile("example.txt"); // Open file for writing

    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    outFile << "Hello, File I/O in C++!\n"; // Write to file
    outFile.close(); // Closes the file: advised but not strictly necessary here 

    return 0;
}
```

⚠️ If the file does not exist, it will be created. If it exists, it will be **overwritten**.  


<a name="1_08_file_io-1-2"></a>
## Reading from a File  

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile("example.txt"); // Open file for reading

    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) { // Read line by line
        std::cout << line << '\n';
    }

    inFile.close();
    return 0;
}
```

-  `std::getline(inFile, line)` reads one line at a time until EOF.  


<a name="1_08_file_io-1-3"></a>
## Appending to a File  

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt", std::ios::app); // Open in append mode

    if (!outFile) {
        std::cerr << "Error opening file for appending.\n";
        return 1;
    }

    outFile << "Appending a new line!\n"; // Append content
    outFile.close();

    return 0;
}
```

- `std::ios::app` ensures new data is added to the end of the file so that it is not overwritten.


<a name="1_08_file_io-1-4"></a>
## Reading and Writing Using `fstream`  

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);

    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    file << "Using fstream to write!\n"; // Writing
    file.seekg(0); // Move read position to beginning

    std::string line;
    while (std::getline(file, line)) { // Reading
        std::cout << line << '\n';
    }

    file.close();
    return 0;
}
```

- `std::ios::in | std::ios::out | std::ios::app` allows both reading and writing.  


<a name="1_08_file_io-1-5"></a>
## Checking File Existence

```cpp

#include <fstream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}
```

- `file.good()` returns `true` if the file exists and is accessible.  


<a name="1_08_file_io-1-6"></a>
## See More

[Standard Library Header \<fstream\>](https://en.cppreference.com/w/cpp/header/fstream)

---
[[⇦ Previous](1_07_basic_io_idx.md)]		[[Next  ⇨](1_09_binary_file_io_idx.md)]		[[Index ⇧](index.md#1_08_file_io_idx.md)]
