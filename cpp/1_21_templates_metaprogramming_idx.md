<a name="1_21_templates_metaprogramming-1"></a>
# Templates and Generic Programming: Advanced Issues

<a name="1_21_templates_metaprogramming-1-1"></a>
## Template Metaprogramming (TMP)

- Templates can be used for **compile-time computation**.

<a name="1_21_templates_metaprogramming-1-1-1"></a>
### `constexpr` and `if constexpr`

- C++17 introduced `if constexpr` to evaluate conditions at compile-time.
- The `if constexpr` block removes unused branches at compile-time.

```cpp
template <typename T>
void process(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integer type\n";
    } else {
        std::cout << "Non-integer type\n";
    }
}
```

<a name="1_21_templates_metaprogramming-1-1-2"></a>
### SFINAE (Substitution Failure Is Not An Error)

- SFINAE allows **template overload selection** based on conditions.

```cpp
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void process(T value) {
    std::cout << "Integer type\n";
}
```
- This function is only enabled if `T` is an integer.


<a name="1_21_templates_metaprogramming-1-2"></a>
## CRTP (Curiously Recurring Template Pattern)

- CRTP is used  for **static polymorphism**.
- Used extensively in C++/WinRT.

```cpp
template <typename Worker>
class IWorker {
public:
    void do_work() {
        static_cast<Worker*>(this)->do_work_impl();
    }
};

class Worker : public IWorker<Worker> {
public:
    void do_work_impl() { std::cout << "Worker do_work_impl\n"; }
};

template<typename T>
void func(IWorker<T> &worker) { // Receives any obj implementing IWorker 
    worker.do_work();
}

int main() {
    Worker w;
    w.do_work();  // Calls Worker::do_work_impl()
    func(w);  
}
```

- Avoids **virtual function overhead**.


<a name="1_21_templates_metaprogramming-1-3"></a>
##  Templates and Inheritance

- Templates can be used as **base classes**.
```cpp
template <typename T>
class Base { };

class Derived : public Base<int> { };
```

- When referring to a **dependent base class member**, use `typename` and `template`:
- Necessary because of name resolution issues: 
    - If used `Base<T>::Type` only, the compiler doesn't know if this is, for example, an static member of `Base<T>`.

```cpp
template <typename T>
class Base {
protected:
    using Type = T;
};

template <typename T>
class Derived : public Base<T> {
    typename Base<T>::Type value;  // Required!
};
```

<a name="1_21_templates_metaprogramming-1-4"></a>
## Performance & Compilation Aspects

- **Header-Only Libraries:** Templates are **defined** in headers because they need to be instantiated at compile-time.
- **Code Bloat:** Every unique template instantiation generates separate code.
- **Link-Time Optimization (LTO):** Helps reduce redundant instantiations.

---
[[⇦ Previous](1_20_templates_idx.md)]		[[Next  ⇨](1_22_static_errors_idx.md)]		[[Index ⇧](index.md#1_21_templates_metaprogramming_idx.md)]
