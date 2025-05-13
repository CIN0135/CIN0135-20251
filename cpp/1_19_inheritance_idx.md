<a name="1_19_inheritance-1"></a>
# Inheritance

- Allows a class (**child**) to derive properties and behavior from another class (**parent**). 
- Enables code reuse, polymorphism, and extensibility.

<a name="1_19_inheritance-1-1"></a>
## Syntax

```cpp
class Parent {
public:
    void show() { std::cout << "Parent class" << std::endl; }
};

class Child : public Parent { // Child class inherits Parent
};
```

↪ `Child` has all public and protected members of `Parent`.

```cpp
int main() {
    Child c;
    c.show(); // Output: Parent class
}
```

↪ `Child` can access `show()` without redefining it.


<a name="1_19_inheritance-1-2"></a>
## Virtual Methods (Polymorphism)

- A **virtual method** allows (but does not require) derived classes to override it, ensuring **dynamic dispatch (late binding)**.

```cpp
class Base {
public:
    virtual void display() { // Virtual function
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Overrides Base::display()
        std::cout << "Derived class display" << std::endl;
    }
};

int main() {
    Base* b = new Derived(); // Polymorphic behavior
    b->display(); // Calls Derived's display()
    delete b;
}
```

↪ Virtual functions ensure correct method is called based on the actual object type, not the pointer type.

<a name="1_19_inheritance-1-3"></a>
## Abstract Classes

- A class is **abstract** if it has at least one **pure virtual function**.
- A pure virtual method has no implementation and **MUST** be defined by each concrete subclass.
- An abstract class cannot be instantiated directly.
- May be used to replace the concept of **interface** in other languages.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};
```
↪ Shape is abstract because `draw()` is pure virtual (`= 0`).


<a name="1_19_inheritance-1-4"></a>
## Concrete Class

- A class is **concrete** if it provides implementations for all its functions.

```cpp
class Circle : public Shape {
public:
    void draw() override {  // pure virtual function implementation
        std::cout << "Drawing Circle" << std::endl; 
    }
};
```

<a name="1_19_inheritance-1-5"></a>
## Types of Inheritance

- The access specifier (`public`, `protected`, `private`) affects **how members are inherited**.

| Inheritance Type | Parent's `public` Members | Parent's `protected` Members | Parent's `private` Members |
|------------------|-------------------------|-----------------------------|----------------------------|
| **Public (`: public`)** | **Public** | **Protected** | Not accessible |
| **Protected (`: protected`)** | **Protected** | **Protected** | Not accessible |
| **Private (`: private`)** | **Private** | **Private** | Not accessible |

```cpp
class Base {
protected:
    int x;
public:
    void show() { std::cout << "Base" << std::endl; }
};

class PublicDerived : public Base {};
class ProtectedDerived : protected Base {};
class PrivateDerived : private Base {};

int main() {
    PublicDerived pub;
    pub.show(); // Allowed

    ProtectedDerived prot;
    // prot.show(); ERROR: show() becomes protected

    PrivateDerived priv;
    // priv.show(); ERROR: show() becomes private
}
```


<a name="1_19_inheritance-1-6"></a>
## Method Overriding

- A **child class** can override a **base class** method.
- Requires **virtual** in base class.
- The `override` keyword ensures compiler checks for proper overriding.

```cpp
class Parent {
public:
    virtual void greet() { std::cout << "Hello from Parent" << std::endl; }
};

class Child : public Parent {
public:
    void greet() override { std::cout << "Hello from Child" << std::endl; }
};
```

<a name="1_19_inheritance-1-7"></a>
##  Virtual Destructors & Abstract Classes

<a name="1_19_inheritance-1-7-1"></a>
###  Virtual Destructors

- Ensure proper cleanup when deleting polymorphic objects.
- If a base class does not provide a virtual destructor, it is not called during child object destruction.

```cpp
class Base {
public:
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Calls both destructors
}
```
↪ **Output**
```
Derived destructor
Base destructor
```

<a name="1_19_inheritance-1-8"></a>
## Multiple Inheritance

- A class can inherit from **multiple base classes**.

```cpp
class A { public: void showA() { std::cout << "A\n"; } };
class B { public: void showB() { std::cout << "B\n"; } };

class C : public A, public B {};
```
↪ `C` now has access to `showA()` and `showB()`.

---
[[⇦ Previous](1_18_smart_pointers_idx.md)]		[[Next  ⇨](1_20_templates_idx.md)]		[[Index ⇧](index.md#1_19_inheritance_idx.md)]
