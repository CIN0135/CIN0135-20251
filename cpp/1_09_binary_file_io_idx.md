<a name="1_09_binary_file_io-1"></a>
# Binary File I/O

- Binary files store data in raw form, preserving structure without conversion. 
- File handling done using `std::ifstream`, `std::ofstream`, and `std::fstream` with the `std::ios::binary` **mode** (`std::ios_base::openmode`).


<a name="1_09_binary_file_io-1-1"></a>
## Writing Binary Data

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    double value;
};

int main() {
    std::ofstream outFile("data.bin", std::ios::binary);

    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    Data d = {1, 99.99}; // Sample data
    outFile.write(reinterpret_cast<char*>(&d), sizeof(d)); // Write binary data
    outFile.close();

    return 0;
}
```

- `reinterpret_cast<char*>` instructs the compiler to look at the structure as a raw byte (char) array for writing.  


<a name="1_09_binary_file_io-1-2"></a>
## Reading Binary Data

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    double value;
};

int main() {
    std::ifstream inFile("data.bin", std::ios::binary);

    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }

    Data d;
    inFile.read(reinterpret_cast<char*>(&d), sizeof(d)); // Read binary data

    std::cout << "ID: " << d.id << ", Value: " << d.value << '\n';

    inFile.close();
    return 0;
}
```

- `inFile.read()` reads bytes "as is" from the file into the into the memory location of the struct.

<a name="1_09_binary_file_io-1-3"></a>
## Appending Binary Data

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    double value;
};

int main() {
    std::ofstream outFile("data.bin", std::ios::binary | std::ios::app);

    if (!outFile) {
        std::cerr << "Error opening file for appending.\n";
        return 1;
    }

    Data d = {2, 123.45};
    outFile.write(reinterpret_cast<char*>(&d), sizeof(d)); // Append binary data

    outFile.close();
    return 0;
}
```

- `std::ios::app` ensures new data is added at the end of the file.


<a name="1_09_binary_file_io-1-4"></a>
## Seeking in Binary Files

- You can move the file pointer to read or write at specific positions using 
	- `seekg()` (input) and 
	- `seekp()` (output).

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    double value;
};

int main() {
    std::fstream file("data.bin", std::ios::binary | std::ios::in | std::ios::out);

    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    file.seekg(0, std::ios::end); // Move to end of file
    std::streampos fileSize = file.tellg(); // Get file size
    int numRecords = fileSize / sizeof(Data);
    std::cout << "Total Records: " << numRecords << '\n';

    if (numRecords > 0) {
        file.seekg(0, std::ios::beg); // Move to the first record
        Data d;
        file.read(reinterpret_cast<char*>(&d), sizeof(d));
        std::cout << "First Record - ID: " << d.id << ", Value: " << d.value << '\n';
    }

    file.close();
    return 0;
}
```

- `seekg(offset, direction)` moves the read pointer, and `tellg()` gets the current position.

---
[[⇦ Previous](1_08_file_io_idx.md)]		[[Next  ⇨](1_10_arrays_idx.md)]		[[Index ⇧](index.md#1_09_binary_file_io_idx.md)]
