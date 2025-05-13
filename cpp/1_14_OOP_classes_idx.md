<a name="1_14_OOP_classes-1"></a>
# Intro to OOP: User-defined types (aka Classes)

- C++ allows user-defined abstract data types (ADT) encapsulating:
    - data/state (member variables)  
    - behaviors/semantics (member functions). 
- External access to class members controlled via **access specifiers**:
    - `public` : externally accassible by any other class/function
    - `private`: externally inaccessible by any other class/function (default)
    - `protected`: externally accessible to subclasses only (see [inheritance](PENDING))

<a name="1_14_OOP_classes-1-1"></a>
## Basic Class Definition

```cpp
#include <iostream>
#include <cmath>

static const double PI = 3.1415;

using namespace std;

class Vector2D {
private:
    double x = 1.0;  // private attributes w/default values
    double y = 1.0;

public:
    // Inline definition of public functions
    double X() const {return x;} // read-only access methods
    double Y() const {return y;} 
    double norm() {
        return sqrt(x*x + y*y);
    }
    // Declaration of public functions
    void scale(double factor);
    void rotate(double angleInDegrees);
};

// Outside the class function definition (Using Scope Resolution Operator ::)
void Vector2D::scale(double factor) {
    x *= factor;
    y *= factor;
}

void Vector2D::rotate(double angleInDegrees) {
    double len = norm();
    if (len==0) return;
    double ang = (angleInDegrees / 180.0 * PI) + asin(y/len);  
    x = len * cos(ang);
    y = len * sin(ang);
}

int main() {
    Vector2D v;
 
    v.scale(2.0);
    std::cout << "|v=(" << v.X() << "," << v.Y() << ")| = " << v.norm() << endl;
    
    v.rotate(90);
    std::cout << "|v=(" << v.X() << "," << v.Y() << ")| = " << v.norm() << endl;
}
```

<a name="1_14_OOP_classes-1-2"></a>
## Operator Overloading

- C++ allows redefining language operators to class-specific behaviour

```cpp
class Vector2D {
// ...
public:
    // ...
    Vector2D operator+(Vector2D other) {
        return Vector2D{ x + other.x, y + other.y };
    }
};
// ...
int main() {
  Vector2D v;
  Vector2D w;
  w.scale(2);
  Vector2D z = v + w;
  std::cout << "|z=(" << z.X() << "," << z.Y() << ")| = " << z.norm() << endl;
}
```

<a name="1_14_OOP_classes-1-3"></a>
## Constructors and Destructors

- **Special member functions** of a class that handle object creation and destruction.  

<a name="1_14_OOP_classes-1-3-1"></a>
### Constructors

- Called **automatically** when an object of a class is created 
- Used to initialize the object
- Same name as the class
- No return type (not even `void`)
- Can be overloaded (multiple constructors with different parameters)

<a name="1_14_OOP_classes-1-3-2"></a>
### Two types of Constructors

<a name="1_14_OOP_classes-1-3-2-1"></a>
#### 1. Default Constructor (No Parameters)

- If not explicitly defined, C++ provides a default constructor that initializes members to default values  

```cpp
class Vector2D {
private: 
    double x;
    double y;
public:
    Vector2D() { // Same initialization as before 
        x = 1.0;
        y = 1.0;
    }
    double X() const {return x;} // read-only access methods
    double Y() const {return y;}
    // ...
};
int main() {
    Vector2D v;
    std::cout << "v=(" << v.X() << ", " << v.Y() << ")" << std::endl; // Output: v=(1, 1)
}
```

<a name="1_14_OOP_classes-1-3-2-2"></a>
#### 2. Parameterized Constructor

- Used to initialize an object with custom values.

```cpp
class Vector2D {
private: 
    double x;
    double y;
public:
    Vector2D() { 
        x = 1.0;
        y = 1.0;
    }
    Vector2D(double x_val, double y_val) {  
        x = x_val;
        y = y_val;
    }
    double X() const {return x;} // read-only access methods
    double Y() const {return y;}
    // ...
};
int main() {
    Vector2D v(2, 3);
    std::cout << "v=(" << v.X() << ", " << v.Y() << ")" << std::endl; // Output: v=(2, 3)
}
```

<a name="1_14_OOP_classes-1-3-3"></a>
### Destructors

- Called **automatically** when an object **goes out of scope** or is **deleted** 
- Its purpose is to clean up resources.
- Same name as the class but prefixed with `~`
- No parameters, no return type
- Only one destructor per class (cannot be overloaded)
- Objects are destructed in the reverse order of creation

```cpp
class Vector2D {
private:
    double x = 1.0;
    double y = 1.0;
public:
    Vector2D() = default; // default constructor
    Vector2D(double x_val, double y_val) { // custom initialization constructor
        x = x_val;
        y = y_val;
    }
    Vector2D(const Vector2D& v) // copy constructor
        std::cout << "Copy constructor from v=(" << v.X() << ", " << v.Y() << ")" << std::endl;
        x = v.x;
        y = v.y;
    }
    ~Vector2D() { // destructor (doesn't do much in this example)
        std::cout << "Destructor of (" << X() << ", " << Y() << ")" << std::endl;
    }
    double X() const {return x;} // read-only access methods
    double Y() const {return y;}
    // ...
};
int main() {
    Vector2D v;
    Vector2D w(v);
    w.scale(2.0);
} 
```
**Output:**
```
Copy constructor from v=(1, 1)
Destructor of (2, 2)
Destructor of (1, 1)
```

<a name="1_14_OOP_classes-1-3-3-1"></a>
#### Default destructors

- If you do not define a destructor in a class, C++ automatically provides a default destructor
which:
    - Performs automatic cleanup for built-in data types (like int, double, char* pointers, etc.).
    - Does nothing special beyond destroying the object—no explicit resource deallocation.
    - Calls the destructors of non-static member objects (if they have destructors).

```cpp
class Basis2D {
private:
    Vector2D u;
    Vector2D v;
public:
    Basis2D(Vector2D a, Vector2D b) { v = a; v = b; }
    // default destructor
};

int main() {    
    Vector2D v;
    Vector2D w(2, 2);
    Basis2D b(v, w);
    std::cout << "Basis initialized." << std::endl;
    v.scale(5.0);
    w.scale(6.0);
    return 0;
}
```
**Output:**
```
Copy constructor from v=(2, 2)
Copy constructor from v=(1, 1)
Destructor of (1, 1)
Destructor of (2, 2)
Basis initialized.
Destructor of (2, 2)
Destructor of (1, 1)
Destructor of (12, 12)
Destructor of (5, 5)
```

<a name="1_14_OOP_classes-1-4"></a>
## Object Instantiation

- In C++, objects can be allocated on either the **stack** or the **heap**, depending on how they are declared.


<a name="1_14_OOP_classes-1-4-1"></a>
### Stack Allocation

- Happens when an object is declared **without using `new`**
- These objects are automatically **created and destroyed** when they go out of scope.
- Avoids memory leaks

```cpp
void stackExample() {
    Vector2D v1(3, 4); // Allocated on the stack
    Basis2D basis(Vector2D(1, 0), Vector2D(0, 1)); // Basis2D allocated on stack

    std::cout << "Norm of v1: " << v1.norm() << std::endl;
} // `v1` and `basis` are automatically destroyed here
```
**Output:**
```
Destructor of (3, 4)
Destructor of (1, 0)
Destructor of (0, 1)
```

<a name="1_14_OOP_classes-1-4-2"></a>
###  Heap Allocation

- Happens when objects are created using `new`.
- The handle is a pointer to the memory location where the object is stored.
- The object remains in memory until `delete` is called on it.
- These objects **must be manually deleted** to avoid memory leaks.

```cpp
void heapExample() {
    Vector2D* v1 = new Vector2D(3, 4); // Allocated on the heap
    Basis2D* basis = new Basis2D(Vector2D(1, 0), Vector2D(0, 1)); // Also on the heap

    std::cout << "Norm of v1: " << v1->norm() << std::endl;
    
    // Manual deletion required!
    delete v1; 
    delete basis; // Calls destructor of `basis`
}
```
**Output:**
```
Destructor of (3, 4)
Destructor of (1, 0)
Destructor of (0, 1)
```

<a name="1_14_OOP_classes-1-4-2-1"></a>
#### ⚠️ Takeaways 
- Use stack allocation whenever possible (automatic cleanup, no leaks).
- Use heap allocation when needed (dynamic objects that outlive function scope).

<a name="1_14_OOP_classes-1-5"></a>
## See More

[Basic rules and idioms for operator overloading](https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729)

---
[[⇦ Previous](1_13_namespaces_idx.md)]		[[Next  ⇨](1_15_references_idx.md)]		[[Index ⇧](index.md#1_14_OOP_classes_idx.md)]
