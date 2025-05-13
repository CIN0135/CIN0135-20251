# Module 01: Introduction to Modern C++
# Table of Contents


<a name="1_01_intro_idx.md"></a>
- [Introduction to Modern C++](1_01_intro_idx.md#1_01_intro-1)
	- [What is C++](1_01_intro_idx.md#1_01_intro-1-1)
	- [Evolution from C\+\+98 to C\+\+20](1_01_intro_idx.md#1_01_intro-1-2)
	- [Key Features of Modern C++](1_01_intro_idx.md#1_01_intro-1-3)
	- [Why C++ is Still Relevant Today](1_01_intro_idx.md#1_01_intro-1-4)

<a name="1_02_csharp_vs_cpp_idx.md"></a>
- [Key Differences Between C# and C++](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1)
	- [Platform Dependency](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-1)
	- [Language Paradigm](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-2)
	- [Execution Environment: Managed vs. Native Code](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-3)
	- [Header Files and Compilation Model](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-4)
	- [Garbage Collection vs. Manual Memory Management](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-5)
	- [RAII vs. `using` Statements for Resource Management](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-6)
	- [No Built-in Properties](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-7)
	- [No Built-in Interfaces](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-8)
	- [No Delegates](1_02_csharp_vs_cpp_idx.md#1_02_csharp_vs_cpp-1-9)

<a name="1_03_compilation_model_idx.md"></a>
- [C++ Compilation Model](1_03_compilation_model_idx.md#1_03_compilation_model-1)
	- [1. Header Files (`.h`, `.hpp`)](1_03_compilation_model_idx.md#1_03_compilation_model-1-1)
	- [2. Translation Units (`.cpp` + Included Headers)](1_03_compilation_model_idx.md#1_03_compilation_model-1-2)
	- [3. Preprocessor (Expands Macros and Includes)](1_03_compilation_model_idx.md#1_03_compilation_model-1-3)
	- [4. Compiler (Compiles Each Translation Unit)](1_03_compilation_model_idx.md#1_03_compilation_model-1-4)
	- [5. Linker (Combines Object Files into Executable)](1_03_compilation_model_idx.md#1_03_compilation_model-1-5)
	- [Putting It All Together](1_03_compilation_model_idx.md#1_03_compilation_model-1-6)
	- [Complete Example](1_03_compilation_model_idx.md#1_03_compilation_model-1-7)

<a name="1_04_main_idx.md"></a>
- [Main Function and Program Execution](1_04_main_idx.md#1_04_main-1)

<a name="1_05_vars_constants_idx.md"></a>
- [Variables and Constants](1_05_vars_constants_idx.md#1_05_vars_constants-1)
	- [Primitive Types](1_05_vars_constants_idx.md#1_05_vars_constants-1-1)
	- [Enumerations (Enums)](1_05_vars_constants_idx.md#1_05_vars_constants-1-2)
	- [Variables](1_05_vars_constants_idx.md#1_05_vars_constants-1-3)
	- [Pointers](1_05_vars_constants_idx.md#1_05_vars_constants-1-4)
	- [Constants](1_05_vars_constants_idx.md#1_05_vars_constants-1-5)
	- [Type aliases](1_05_vars_constants_idx.md#1_05_vars_constants-1-6)
	- [Compile-time Constant Expressions](1_05_vars_constants_idx.md#1_05_vars_constants-1-7)

<a name="1_06_control_flow_idx.md"></a>
- [Control Flow](1_06_control_flow_idx.md#1_06_control_flow-1)
	- [Conditional Statements](1_06_control_flow_idx.md#1_06_control_flow-1-1)
	- [Looping Constructs](1_06_control_flow_idx.md#1_06_control_flow-1-2)
	- [Jump Statements](1_06_control_flow_idx.md#1_06_control_flow-1-3)

<a name="1_07_basic_io_idx.md"></a>
- [Basic I/O](1_07_basic_io_idx.md#1_07_basic_io-1)
	- [Output with `std::cout`](1_07_basic_io_idx.md#1_07_basic_io-1-1)
	- [Read input with `std::cin`](1_07_basic_io_idx.md#1_07_basic_io-1-2)
	- [Inputting Strings](1_07_basic_io_idx.md#1_07_basic_io-1-3)
	- [Error Messages with `std::cerr`](1_07_basic_io_idx.md#1_07_basic_io-1-4)
	- [Logging with `std::clog`](1_07_basic_io_idx.md#1_07_basic_io-1-5)

<a name="1_08_file_io_idx.md"></a>
- [File I/O](1_08_file_io_idx.md#1_08_file_io-1)
	- [Writing to a File](1_08_file_io_idx.md#1_08_file_io-1-1)
	- [Reading from a File](1_08_file_io_idx.md#1_08_file_io-1-2)
	- [Appending to a File](1_08_file_io_idx.md#1_08_file_io-1-3)
	- [Reading and Writing Using `fstream`](1_08_file_io_idx.md#1_08_file_io-1-4)
	- [Checking File Existence](1_08_file_io_idx.md#1_08_file_io-1-5)
	- [See More](1_08_file_io_idx.md#1_08_file_io-1-6)

<a name="1_09_binary_file_io_idx.md"></a>
- [Binary File I/O](1_09_binary_file_io_idx.md#1_09_binary_file_io-1)
	- [Writing Binary Data](1_09_binary_file_io_idx.md#1_09_binary_file_io-1-1)
	- [Reading Binary Data](1_09_binary_file_io_idx.md#1_09_binary_file_io-1-2)
	- [Appending Binary Data](1_09_binary_file_io_idx.md#1_09_binary_file_io-1-3)
	- [Seeking in Binary Files](1_09_binary_file_io_idx.md#1_09_binary_file_io-1-4)

<a name="1_10_arrays_idx.md"></a>
- [Arrays](1_10_arrays_idx.md#1_10_arrays-1)
	- [Basic Declaration](1_10_arrays_idx.md#1_10_arrays-1-1)
	- [Initialization at Declaration](1_10_arrays_idx.md#1_10_arrays-1-2)
	- [Accessing and Modifying Elements](1_10_arrays_idx.md#1_10_arrays-1-3)
	- [Iteration](1_10_arrays_idx.md#1_10_arrays-1-4)
	- [Multidimensional Arrays](1_10_arrays_idx.md#1_10_arrays-1-5)
	- [Arrays and Pointers](1_10_arrays_idx.md#1_10_arrays-1-6)

<a name="1_11_strings_idx.md"></a>
- [Strings](1_11_strings_idx.md#1_11_strings-1)
	- [C-Style Strings (`char` Arrays)](1_11_strings_idx.md#1_11_strings-1-1)
	- [`std::string` Class](1_11_strings_idx.md#1_11_strings-1-2)
	- [Converting Between C-Strings and `std::string`](1_11_strings_idx.md#1_11_strings-1-3)
	- [Input and Output with Strings](1_11_strings_idx.md#1_11_strings-1-4)

<a name="1_12_functions_idx.md"></a>
- [Functions](1_12_functions_idx.md#1_12_functions-1)
	- [Function Prototypes and Definitions](1_12_functions_idx.md#1_12_functions-1-1)
	- [Function Overloading](1_12_functions_idx.md#1_12_functions-1-2)
	- [Default Arguments](1_12_functions_idx.md#1_12_functions-1-3)
	- [Inline Functions](1_12_functions_idx.md#1_12_functions-1-4)

<a name="1_13_namespaces_idx.md"></a>
- [Namespaces](1_13_namespaces_idx.md#1_13_namespaces-1)
	- [`using` Directive](1_13_namespaces_idx.md#1_13_namespaces-1-1)
	- [Nested Namespaces](1_13_namespaces_idx.md#1_13_namespaces-1-2)
	- [Anonymous (Unnamed) Namespaces](1_13_namespaces_idx.md#1_13_namespaces-1-3)
	- [Standard (`std`) Namespace](1_13_namespaces_idx.md#1_13_namespaces-1-4)

<a name="1_14_OOP_classes_idx.md"></a>
- [Intro to OOP: User-defined types (aka Classes)](1_14_OOP_classes_idx.md#1_14_OOP_classes-1)
	- [Basic Class Definition](1_14_OOP_classes_idx.md#1_14_OOP_classes-1-1)
	- [Operator Overloading](1_14_OOP_classes_idx.md#1_14_OOP_classes-1-2)
	- [Constructors and Destructors](1_14_OOP_classes_idx.md#1_14_OOP_classes-1-3)
	- [Object Instantiation](1_14_OOP_classes_idx.md#1_14_OOP_classes-1-4)
	- [See More](1_14_OOP_classes_idx.md#1_14_OOP_classes-1-5)

<a name="1_15_references_idx.md"></a>
- [References (`&`)](1_15_references_idx.md#1_15_references-1)
	- [Syntax of References](1_15_references_idx.md#1_15_references-1-1)
	- [Properties of References](1_15_references_idx.md#1_15_references-1-2)
	- [Using References in Functions](1_15_references_idx.md#1_15_references-1-3)
	- [Unmutable `const` References](1_15_references_idx.md#1_15_references-1-4)
	- [When to Use References?](1_15_references_idx.md#1_15_references-1-5)

<a name="1_16_rule_of_five_idx.md"></a>
- [RAII and the Rule of Five](1_16_rule_of_five_idx.md#1_16_rule_of_five-1)
	- [RAII](1_16_rule_of_five_idx.md#1_16_rule_of_five-1-1)
	- [The Rule of Five](1_16_rule_of_five_idx.md#1_16_rule_of_five-1-2)

<a name="1_17_rule_of_five_pt2_idx.md"></a>
- [RAII and The Rule of Five (Continued)](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1)
	- [Move Semantics in C++](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1-1)
	- [4. Move Constructor](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1-2)
	- [5. Move Assignment Operator](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1-3)
	- [How Does the Compiler Decide Between Copying and Moving?](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1-4)
	- [Rule of Five Summary](1_17_rule_of_five_pt2_idx.md#1_17_rule_of_five_pt2-1-5)

<a name="1_18_smart_pointers_idx.md"></a>
- [Smart Pointers (`std::unique_ptr` & `std::shared_ptr`)](1_18_smart_pointers_idx.md#1_18_smart_pointers-1)
	- [`std::unique_ptr` – Exclusive Ownership](1_18_smart_pointers_idx.md#1_18_smart_pointers-1-1)
	- [`std::shared_ptr` – Shared Ownership](1_18_smart_pointers_idx.md#1_18_smart_pointers-1-2)
	- [Key Differences Between `std::unique_ptr` and `std::shared_ptr`](1_18_smart_pointers_idx.md#1_18_smart_pointers-1-3)
	- [Smart Pointers and the Rule of Five](1_18_smart_pointers_idx.md#1_18_smart_pointers-1-4)

<a name="1_19_inheritance_idx.md"></a>
- [Inheritance](1_19_inheritance_idx.md#1_19_inheritance-1)
	- [Syntax](1_19_inheritance_idx.md#1_19_inheritance-1-1)
	- [Virtual Methods (Polymorphism)](1_19_inheritance_idx.md#1_19_inheritance-1-2)
	- [Abstract Classes](1_19_inheritance_idx.md#1_19_inheritance-1-3)
	- [Concrete Class](1_19_inheritance_idx.md#1_19_inheritance-1-4)
	- [Types of Inheritance](1_19_inheritance_idx.md#1_19_inheritance-1-5)
	- [Method Overriding](1_19_inheritance_idx.md#1_19_inheritance-1-6)
	- [Virtual Destructors & Abstract Classes](1_19_inheritance_idx.md#1_19_inheritance-1-7)
	- [Multiple Inheritance](1_19_inheritance_idx.md#1_19_inheritance-1-8)

<a name="1_20_templates_idx.md"></a>
- [Templates and Generic Programming](1_20_templates_idx.md#1_20_templates-1)
	- [Function Templates](1_20_templates_idx.md#1_20_templates-1-1)
	- [Class Templates](1_20_templates_idx.md#1_20_templates-1-2)
	- [Template Instantiation & Specialization](1_20_templates_idx.md#1_20_templates-1-3)
	- [Variadic Templates (C++11)](1_20_templates_idx.md#1_20_templates-1-4)
	- [Non-Type Template Parameters](1_20_templates_idx.md#1_20_templates-1-5)
	- [Template Aliases & Deduction](1_20_templates_idx.md#1_20_templates-1-6)

<a name="1_21_templates_metaprogramming_idx.md"></a>
- [Templates and Generic Programming: Advanced Issues](1_21_templates_metaprogramming_idx.md#1_21_templates_metaprogramming-1)
	- [Template Metaprogramming (TMP)](1_21_templates_metaprogramming_idx.md#1_21_templates_metaprogramming-1-1)
	- [CRTP (Curiously Recurring Template Pattern)](1_21_templates_metaprogramming_idx.md#1_21_templates_metaprogramming-1-2)
	- [Templates and Inheritance](1_21_templates_metaprogramming_idx.md#1_21_templates_metaprogramming-1-3)
	- [Performance & Compilation Aspects](1_21_templates_metaprogramming_idx.md#1_21_templates_metaprogramming-1-4)

<a name="1_22_static_errors_idx.md"></a>
- [Error Handling](1_22_static_errors_idx.md#1_22_static_errors-1)
<a name="1_22_static_errors_idx.md"></a>
- [Compile Time (static) Error-check](1_22_static_errors_idx.md#1_22_static_errors-2)
	- [`static_assert`: Compile Time Assertions (C++11)](1_22_static_errors_idx.md#1_22_static_errors-2-1)
	- [`constexpr` for Compile-time Evaluation (C++11)](1_22_static_errors_idx.md#1_22_static_errors-2-2)
	- [SFINAE (Substitution Failure Is Not An Error)](1_22_static_errors_idx.md#1_22_static_errors-2-3)
	- [Type Traits](1_22_static_errors_idx.md#1_22_static_errors-2-4)
	- [Prevent Instantiation Using Deleted Functions](1_22_static_errors_idx.md#1_22_static_errors-2-5)
	- [`concepts` (C++20)](1_22_static_errors_idx.md#1_22_static_errors-2-6)
	- [Learn more](1_22_static_errors_idx.md#1_22_static_errors-2-7)

<a name="1_23_exceptions_idx.md"></a>
- [Runtime Errors & Exception Handling](1_23_exceptions_idx.md#1_23_exceptions-1)
	- [Assertions (`assert`)](1_23_exceptions_idx.md#1_23_exceptions-1-1)
	- [Exception Handling (`try`, `catch`, `throw`)](1_23_exceptions_idx.md#1_23_exceptions-1-2)
	- [`noexcept`: Declaring Non-Throwing Functions](1_23_exceptions_idx.md#1_23_exceptions-1-3)
	- [Standard Exception Hierarchy (`std::exception`)](1_23_exceptions_idx.md#1_23_exceptions-1-4)
	- [Learn More](1_23_exceptions_idx.md#1_23_exceptions-1-5)

<a name="1_24_error_as_values_idx.md"></a>
- [Errors As Values](1_24_error_as_values_idx.md#1_24_error_as_values-1)
	- [Representing Optional Values - `std::optional` (C++17)](1_24_error_as_values_idx.md#1_24_error_as_values-1-1)
	- [Representing Multiple Possible Outcomes - `std::variant` (C++17)](1_24_error_as_values_idx.md#1_24_error_as_values-1-2)
	- [Comparison](1_24_error_as_values_idx.md#1_24_error_as_values-1-3)

<a name="1_25_stl_overview_idx.md"></a>
- [C++ Standard Template Library (STL) Overview](1_25_stl_overview_idx.md#1_25_stl_overview-1)
	- [1. Containers](1_25_stl_overview_idx.md#1_25_stl_overview-1-1)
	- [2. Iterators](1_25_stl_overview_idx.md#1_25_stl_overview-1-2)
	- [3. Algorithms](1_25_stl_overview_idx.md#1_25_stl_overview-1-3)
	- [4. Function Objects (Functors) & Utilities](1_25_stl_overview_idx.md#1_25_stl_overview-1-4)

<a name="1_26_vector_idx.md"></a>
- [`std::vector`](1_26_vector_idx.md#1_26_vector-1)
	- [Creation/Destruction](1_26_vector_idx.md#1_26_vector-1-1)
	- [Memory Management and Capacity](1_26_vector_idx.md#1_26_vector-1-2)
	- [Accessing Elements](1_26_vector_idx.md#1_26_vector-1-3)
	- [Adding and Removing Elements](1_26_vector_idx.md#1_26_vector-1-4)
	- [Traversing a `vector`](1_26_vector_idx.md#1_26_vector-1-5)
	- [Moving and Swapping](1_26_vector_idx.md#1_26_vector-1-6)

<a name="1_27_maps_idx.md"></a>
- [`std::map`](1_27_maps_idx.md#1_27_maps-1)
	- [Iterating Over](1_27_maps_idx.md#1_27_maps-1-1)
	- [Lookup](1_27_maps_idx.md#1_27_maps-1-2)
	- [Using `std::map` with User-Defined Classes as Keys](1_27_maps_idx.md#1_27_maps-1-3)
	- [Using `std::map` with User-Defined Classes as Values](1_27_maps_idx.md#1_27_maps-1-4)

<a name="1_28_unordered_maps_idx.md"></a>
- [`std::unordered_map` (vs. `std::map`)](1_28_unordered_maps_idx.md#1_28_unordered_maps-1)
	- [Using `std::unordered_map` with Custom Classes](1_28_unordered_maps_idx.md#1_28_unordered_maps-1-1)

<a name="1_29_iterators_idx.md"></a>
- [Iterators](1_29_iterators_idx.md#1_29_iterators-1)
	- [What are iterators for?](1_29_iterators_idx.md#1_29_iterators-1-1)
	- [What is an Iterator?](1_29_iterators_idx.md#1_29_iterators-1-2)
	- [Types of Iterators](1_29_iterators_idx.md#1_29_iterators-1-3)
	- [Common Iterator Operations](1_29_iterators_idx.md#1_29_iterators-1-4)
	- [Using Iterators in STL Containers](1_29_iterators_idx.md#1_29_iterators-1-5)
	- [Iterator Invalidation](1_29_iterators_idx.md#1_29_iterators-1-6)
	- [Defining a Custom Iterator](1_29_iterators_idx.md#1_29_iterators-1-7)
	- [See More](1_29_iterators_idx.md#1_29_iterators-1-8)

<a name="1_30_algorithms_idx.md"></a>
- [Algorithms](1_30_algorithms_idx.md#1_30_algorithms-1)
	- [Core Concepts](1_30_algorithms_idx.md#1_30_algorithms-1-1)
	- [Examples of STL Algorithms](1_30_algorithms_idx.md#1_30_algorithms-1-2)
	- [Commonly Used STL Algorithms](1_30_algorithms_idx.md#1_30_algorithms-1-3)
	- [See More](1_30_algorithms_idx.md#1_30_algorithms-1-4)

<a name="1_31_threads_idx.md"></a>
- [Concurrency](1_31_threads_idx.md#1_31_threads-1)
	- [Threads (`std::thread`)](1_31_threads_idx.md#1_31_threads-1-1)
	- [Mutexes and Locks](1_31_threads_idx.md#1_31_threads-1-2)
	- [Making a Thread Wait (Synchronization)](1_31_threads_idx.md#1_31_threads-1-3)
	- [Atomic Operations (`std::atomic`)](1_31_threads_idx.md#1_31_threads-1-4)
	- [Parallel Algorithms (`std::execution`, C++17)](1_31_threads_idx.md#1_31_threads-1-5)
	- [See more](1_31_threads_idx.md#1_31_threads-1-6)

<a name="1_32_coroutines_idx.md"></a>
- [Coroutines](1_32_coroutines_idx.md#1_32_coroutines-1)
	- [What Are Coroutines?](1_32_coroutines_idx.md#1_32_coroutines-1-1)
	- [Using a Coroutine (Library User Perspective)](1_32_coroutines_idx.md#1_32_coroutines-1-2)
	- [Defining a Coroutine](1_32_coroutines_idx.md#1_32_coroutines-1-3)
	- [Putting It All Together](1_32_coroutines_idx.md#1_32_coroutines-1-4)
	- [Exemple: Number Generator](1_32_coroutines_idx.md#1_32_coroutines-1-5)
	- [Example: Asynchronous Computation](1_32_coroutines_idx.md#1_32_coroutines-1-6)
	- [See More](1_32_coroutines_idx.md#1_32_coroutines-1-7)

