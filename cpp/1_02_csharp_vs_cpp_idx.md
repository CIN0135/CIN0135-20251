<a name="1_02_csharp_vs_cpp-1"></a>
# Key Differences Between C# and C++

- C# and C++ are both powerful programming languages, but they have significant differences in terms of syntax, memory management, and usage. 

<a name="1_02_csharp_vs_cpp-1-1"></a>
## Platform Dependency

- C# (Cross-Platform with .NET Core)
	```csharp
	using System;

	class Program
	{
		static void Main()
		{
			Console.WriteLine("C# runs on multiple platforms with .NET Core");
		}
	}
	```
- C++ (Platform-Dependent)
	```cpp
	#include <iostream>

	int main() {
		std::cout << "C++ code must be recompiled for each platform" << std::endl;
		return 0;
	}
	```

<a name="1_02_csharp_vs_cpp-1-2"></a>
## Language Paradigm

- C# is primarily object-oriented
	```csharp
	using System;

	class Animal
	{
		public virtual void Speak()
		{
			Console.WriteLine("Animal speaks");
		}
	}

	class Dog : Animal
	{
		public override void Speak()
		{
			Console.WriteLine("Dog barks");
		}
	}

	class Program
	{
		static void Main()
		{
			Animal myDog = new Dog();
			myDog.Speak(); // Output: Dog barks
		}
	}
	```
- C++ is multiparadigm (oject-oriented, procedural, functional, generic programming).
	```cpp
	#include <iostream>

	// Procedural function
	void Speak() {
		std::cout << "Animal speaks" << std::endl;
	}

	// Object-oriented class
	class Dog {
	public:
		void Speak() {
			std::cout << "Dog barks" << std::endl;
		}
	};

	int main() {
		// Procedural call
		Speak();

		// Object-oriented call
		Dog myDog;
		myDog.Speak();
		return 0;
	}
	```

<a name="1_02_csharp_vs_cpp-1-3"></a>
## Execution Environment: Managed vs. Native Code

- **C# (Managed Code with .NET Runtime):** C# is compiled to Intermediate Language (IL) and executed by the .NET runtime.
  ```csharp
  using System;
  
  class Program {
      static void Main() {
          Console.WriteLine("Hello from C#");
      }
  }
  ```
  - C# code is compiled into Intermediate Language (IL) and runs on the .NET runtime (CLR), enabling garbage collection and runtime optimizations.

- **C++ (Compiled to Native Machine Code):**
  ```cpp
  #include <iostream>
  
  int main() {
      std::cout << "Hello from C++" << std::endl;
      return 0;
  }
  ```
  - C++ code is compiled directly into native machine code, providing high performance and fine control over system resources.

<a name="1_02_csharp_vs_cpp-1-4"></a>
## Header Files and Compilation Model

- **C# (Single Compilation Unit, No Headers):**
  ```csharp
  public class Example {
      public void SayHello() {
          Console.WriteLine("Hello from C#");
      }
  }
  ```
  - C# uses assemblies (`.dll`, `.exe`) with all dependencies resolved at compile time.

- **C++ (Separate Compilation with Header Files):**
  ```cpp
  // Example.h
  class Example {
  public:
      void SayHello();
  };
  
  // Example.cpp
  #include "Example.h"
  #include <iostream>
  
  void Example::SayHello() {
      std::cout << "Hello from C++" << std::endl;
  }
  ```
  - C++ requires header files for declarations and separate compilation units for definitions.

<a name="1_02_csharp_vs_cpp-1-5"></a>
## Garbage Collection vs. Manual Memory Management

- **C# (Garbage Collection):**
  ```csharp
  class Example {
      public Example() {
          Console.WriteLine("Object created");
      }
      ~Example() {
          Console.WriteLine("Object destroyed");
      }
  }
  
  class Program {
      static void Main() {
          Example obj = new Example(); // Object created
      } // Object will be destroyed later by the garbage collector
  }
  ```
  - C# automatically manages memory through garbage collection.

- **C++ (Manual Memory Management with Smart Pointers):**
  ```cpp
  #include <iostream>
  #include <memory>
  
  class Example {
  public:
      Example() { std::cout << "Object created\n"; }
      ~Example() { std::cout << "Object destroyed\n"; }
  };
  
  int main() {
      std::unique_ptr<Example> obj = std::make_unique<Example>(); // Object created
  } // Object is destroyed as unique_ptr goes out of scope
  ```
  - C++ requires explicit memory management or smart pointers to prevent memory leaks.

<a name="1_02_csharp_vs_cpp-1-6"></a>
## RAII vs. `using` Statements for Resource Management

- **C# (`using` Statement for Cleanup):**
  ```csharp
  using System;
  using System.IO;
  
  class Program {
      static void Main() {
          using (StreamWriter file = new StreamWriter("file.txt")) {
              file.WriteLine("Hello, world!");
          } // File is closed automatically here
      }
  }
  ```

- **C++ (RAII with Destructors):**
  ```cpp
  #include <iostream>
  #include <fstream>
  
  class FileHandler {
  public:
      FileHandler(const std::string& filename) {
          file.open(filename);
      }
      ~FileHandler() {
          file.close();
      }
  private:
      std::ofstream file;
  };
  
  int main() {
      FileHandler handler("file.txt");
      return 0; // File automatically closes when handler goes out of scope
  }
  ```

<a name="1_02_csharp_vs_cpp-1-7"></a>
## No Built-in Properties

- **C# (Built-in Property Support):**
  ```csharp
  public class Person {
      public string Name { get; set; }
  }
  
  class Program {
      static void Main() {
          Person p = new Person { Name = "Alice" };
          Console.WriteLine(p.Name);
      }
  }
  ```

- **C++ (Manual Getters and Setters):**
  ```cpp
  #include <iostream>
  #include <string>
  
  class Person {
  private:
      std::string name;
  public:
      void SetName(const std::string& newName) { name = newName; }
      std::string GetName() const { return name; }
  };
  
  int main() {
      Person p;
      p.SetName("Alice");
      std::cout << p.GetName() << std::endl;
  }
  ```

<a name="1_02_csharp_vs_cpp-1-8"></a>
## No Built-in Interfaces

- **C# (Interfaces Supported):**
  ```csharp
  interface IShape {
      void Draw();
  }
  
  class Circle : IShape {
      public void Draw() {
          Console.WriteLine("Drawing Circle");
      }
  }
  ```

- **C++ (Manual Interface Implementation via Abstract Classes):**
  ```cpp
  #include <iostream>
  
  class IShape {
  public:
      virtual void Draw() = 0; // Pure virtual function
      virtual ~IShape() = default;
  };
  
  class Circle : public IShape {
  public:
      void Draw() override {
          std::cout << "Drawing Circle" << std::endl;
      }
  };
  ```

<a name="1_02_csharp_vs_cpp-1-9"></a>
## No Delegates

- **C# (Built-in Delegates and Events):**
  ```csharp
  using System;
  
  class Program {
      delegate void MyDelegate(string message);
  
      static void PrintMessage(string message) {
          Console.WriteLine(message);
      }
  
      static void Main() {
          MyDelegate del = PrintMessage;
          del("Hello from delegate!");
      }
  }
  ```

- **C++ (Function Pointers or `std::function` Instead of Delegates):**
  ```cpp
  #include <iostream>
  #include <functional>
  
  void PrintMessage(const std::string& message) {
      std::cout << message << std::endl;
  }
  
  int main() {
      std::function<void(std::string)> myDelegate = PrintMessage;
      myDelegate("Hello from function object!");
  }
  ```


---
[[⇦ Previous](1_01_intro_idx.md)]		[[Next  ⇨](1_03_compilation_model_idx.md)]		[[Index ⇧](index.md#1_02_csharp_vs_cpp_idx.md)]
