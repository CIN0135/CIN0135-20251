<a name="1_13_namespaces-1"></a>
# Namespaces

- Namespaces in C++ help organize code and prevent **name conflicts** by grouping related functions, classes, and variables under a unique scope.
- Without namespaces, if two libraries define a function or class with the same name, a **name collision** occurs. 
- Namespaces help avoid this by encapsulating identifiers.
- A namespace is defined using the `namespace` keyword:
- The **scope resolution operator** `::` is used to identity the namespace of an identifier.


```cpp
#include <iostream>

void print() { std::cout << "Global print\n"; }

namespace Library {
    void print() { std::cout << "Library print\n"; }
}

int main() {
    print();          // Calls global print
    Library::print(); // Calls Library's print
}
```

<a name="1_13_namespaces-1-1"></a>
## `using` Directive 

- The `using namespace` directive brings **all** names from a namespace into the current scope:
```cpp
using namespace MyNamespace;
greet();  // No need for MyNamespace:: prefix
```
- However we can narrow it down so specific names:
```cpp
using MyNamespace::greet;
greet();  // Only MyNamespace::greet() is available
```

<a name="1_13_namespaces-1-2"></a>
## Nested Namespaces

- Namespaces can be nested in an hierarchycal structure.
```cpp
namespace A {
    namespace B {
        void sayHello() { std::cout << "Hello from A::B\n"; }
    }
}
A::B::sayHello();
```

<a name="1_13_namespaces-1-3"></a>
## Anonymous (Unnamed) Namespaces

- Anonymous namespaces** restrict access **to the current file** (similar to `static` for functions).
```cpp
namespace {
    void hiddenFunction() { std::cout << "Only accessible in this file\n"; }
}
```

<a name="1_13_namespaces-1-4"></a>
## Standard (`std`) Namespace

- C++ standard library identifiers, such as `std::cout` and `std::vector`, are inside the `std` namespace.

```cpp
#include <iostream>
using namespace std;  // Avoid this in large projects!

cout << "Hello, world!" << endl;  // std::cout is now accessible without std::
```

---
[[⇦ Previous](1_12_functions_idx.md)]		[[Next  ⇨](1_14_OOP_classes_idx.md)]		[[Index ⇧](index.md#1_13_namespaces_idx.md)]
