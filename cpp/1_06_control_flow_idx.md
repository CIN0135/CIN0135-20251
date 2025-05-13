<a name="1_06_control_flow-1"></a>
# Control Flow

<a name="1_06_control_flow-1-1"></a>
## Conditional Statements  

<a name="1_06_control_flow-1-1-1"></a>
### if

- Executes a block if a condition is true  

  ```cpp
  if (x > 0) {
      // code
  }
  ```

<a name="1_06_control_flow-1-1-2"></a>
### if-else  

- Executes one block if true, another if false  

  ```cpp
  if (x > 0) {
      // code
  } else {
      // code
  }
  ```

<a name="1_06_control_flow-1-1-3"></a>
### else if

- Checks multiple conditions  

  ```cpp
  if (x > 10) {
      // code
  } else if (x > 5) {
      // code
  } else {
      // code
  }
  ```

<a name="1_06_control_flow-1-1-4"></a>
### switch  

- Multi-way branching based on **integral (integers, char, bool) and enum** values  

  ```cpp
  switch (x) {
      case 1:
          // code
          break;
      case 2:
          // code
          break;
      default:
          // code
  }
  ```


<a name="1_06_control_flow-1-2"></a>
## Looping Constructs  

<a name="1_06_control_flow-1-2-1"></a>
### for  

- Loop with initialization, condition, and increment  

  ```cpp
  for (int i = 0; i < 10; i++) {
      // code
  }
  ```

<a name="1_06_control_flow-1-2-2"></a>
### while  

- Loops while a condition is true  

  ```cpp
  while (x > 0) {
      // code
  }
  ```

<a name="1_06_control_flow-1-2-3"></a>
### do-while  

- Executes at least once, then loops while the condition is true  

  ```cpp
  do {
      // code
  } while (x > 0);
  ```

<a name="1_06_control_flow-1-3"></a>
## Jump Statements  

<a name="1_06_control_flow-1-3-1"></a>
### break 

- Exits a loop or `switch` statement  

  ```cpp
  if (x == 5) break;
  ```

<a name="1_06_control_flow-1-3-2"></a>
### continue  

- Skips the current iteration and moves to the next  

  ```cpp
  for (int i = 0; i < 10; i++) {
      if (i == 5) continue;
      // code
  }
  ```

<a name="1_06_control_flow-1-3-3"></a>
### return

- Exits a function, optionally returning a value  

  ```cpp
  return x;
  ```

<a name="1_06_control_flow-1-3-4"></a>
### goto _(Avoid)_  

- Jumps to a labeled statement  

  ```cpp
  goto label;
  label:
      // code
  ```

---
[[⇦ Previous](1_05_vars_constants_idx.md)]		[[Next  ⇨](1_07_basic_io_idx.md)]		[[Index ⇧](index.md#1_06_control_flow_idx.md)]
