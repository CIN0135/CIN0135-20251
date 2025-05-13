<a name="1_31_threads-1"></a>
# Concurrency

- **Concurrency** is the "conceptual" excution of two or more computation **tasks** simultaneously.
- In practice, due to limited computational resources, it is realised by intercalating operations from several tasks.
- If no explicit control is enforced, the OS schedules which operation to run at a given time.
- The C++ Standard Concurrency Model was introduced in **C++11** and has been expanded in later versions (C++14, C++17, C++20) to provide a structured way of writing concurrent and parallel programs. 


<a name="1_31_threads-1-1"></a>
## Threads (`std::thread`)

- A thread is a system-level representation of a task.
- Each thread has its own execution context but shares memory with other threads in the same process.

```cpp
#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from a separate thread!" << std::endl;
}

int main() {
    std::thread t(printMessage); // Spawns a new thread
    t.join(); // Wait for the thread to finish
    return 0;
}
```
- The `thread` constructor takes in a function, function object (functor), or a lambda expression.
- `join()`: Ensures that the main thread waits for `t` to finish before exiting.


<a name="1_31_threads-1-1-1"></a>
### Passing Data into a Thread  

- When spawning a thread, you often need to pass data into it. 
- There are multiple ways to do this, including: 
	- by value
	- by reference
	- using lambdas, and 
	- using `std::move` for efficient transfer of large objects


<a name="1_31_threads-1-1-1-1"></a>
####  Passing Data by Value

- The thread function receives **a copy** of the data.

```cpp
#include <iostream>
#include <thread>

void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

int main() {
    int x = 42;
    std::thread t(printNumber, x); // x is copied into the thread
    t.join();
    return 0;
}
```

<a name="1_31_threads-1-1-1-2"></a>
####  Passing Data by Reference

- Avoids unnecessary copies.
- Must use `std::ref()` to ensure the reference is correctly captured.

```cpp
#include <iostream>
#include <thread>

void modifyValue(int &num) {
    num += 10; 
    std::cout << "Modified Number: " << num << std::endl;
}

int main() {
    int x = 42;
    std::thread t(modifyValue, std::ref(x)); // Pass x by reference using std::ref
    t.join();
    std::cout << "Value in main: " << x << std::endl; // x is modified
    return 0;
}
```
  ⚠️ **Be careful** about referenced objects' lifetimes.


<a name="1_31_threads-1-1-1-3"></a>
####  Passing Data Using Lambda Functions

- Using a **lambda function** makes it easy to capture local variables.

```cpp
#include <iostream>
#include <thread>

int main() {
    int x = 42;
    std::thread t([x]() { // Captures x by value
        std::cout << "Captured Value: " << x << std::endl;
    });
    t.join();
    return 0;
}
```

- You can modify data inside the lambda by capturing it by reference

```cpp
std::thread t([&x]() {
    x += 10;
    std::cout << "Modified inside thread: " << x << std::endl;
});
```

<a name="1_31_threads-1-1-1-4"></a>
####  Moving Large Objects into a Thread

- If an object is **large**, copying it may be inefficient. 
- Instead, use `std::move()` to transfer ownership of the data to the thread.

```cpp
#include <iostream>
#include <thread>
#include <string>

void processString(std::string str) {
    std::cout << "Processing: " << str << std::endl;
}

int main() {
    std::string data = "Hello, World!";
    std::thread t(processString, std::move(data)); // Move instead of copy
    t.join();
    
    // data is now empty
    std::cout << "After move, data: " << data << std::endl;
    return 0;
}
```

<a name="1_31_threads-1-1-2"></a>
### Detaching a thread

- In general, the spawned thread is under control of its originator through the thead object (handle).
- `std::thread::detach()` is a method that allows a thread to run **independently** of the thread that created it. 
- Once detached, the thread continues **in the background** and the system is responsible for cleaning up its resources when it finishes.
- The parent (calling) thread **does not** need to `join()` the detached thread.
- Once a thread is detached, there is **no way** to check its status, return value, or exceptions.
- After calling `detach()`, the thread is said to be a **daemon thread**.
- Best used for **Fire-and-forget tasks** that will clean up themselves.

```cpp
#include <iostream>
#include <thread>
#include <chrono>

void backgroundTask() {
	for (int i = 0; i< 1000; ++i) {
		// do something
	}
    std::cout << "Background task finished!\n";
}

int main() {
    std::thread t(backgroundTask);
    t.detach(); // The thread now runs independently

    std::cout << "Main thread is free to continue...\n";
	// There is no way to check if backgroundTask is done
    return 0;
}
```


<a name="1_31_threads-1-2"></a>
## Mutexes and Locks 

- Multiple threads can access the same memory space.
- This might create data inconsistencies known as **race conditions**.
- **Mutexes** (Mutual Exclusion Objects) prevent data races when multiple threads access shared resources.
- The basic mechanism is to surround critical data access by a mutex lock/unlock pair.

- `std::lock_guard<std::mutex>` ensures automatic locking/unlocking.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void safePrint(int id) {
    std::lock_guard<std::mutex> lock(mtx); // Acquire a lock on the mutex
    std::cout << "Thread " << id << " is printing safely.\n";
	// lock is destroyed, automatically relasing the mutex
}

int main() {
    std::thread t1(safePrint, 1);
    std::thread t2(safePrint, 2);
    
    t1.join();
    t2.join();
    return 0;
}
```

- `std::unique_lock<std::mutex>` provides more flexibility (e.g., deferred locking).

```cpp
#include <iostream>
#include <mutex>
#include <thread>
 
struct Box {
    explicit Box(int num) : num_things{num} {}
 
    int num_things;
    std::mutex m;
};
 
void transfer(Box& from, Box& to, int num) {
    // don't actually take the locks yet
    std::unique_lock lock1{from.m, std::defer_lock};
    std::unique_lock lock2{to.m, std::defer_lock};
 
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);
 
    from.num_things -= num;
    to.num_things += num;
 
    // “from.m” and “to.m” mutexes unlocked in unique_lock dtors
}
 
int main() {
    Box acc1{100};
    Box acc2{50};
 
    std::thread t1{transfer, std::ref(acc1), std::ref(acc2), 10};
    std::thread t2{transfer, std::ref(acc2), std::ref(acc1), 5};
 
    t1.join();
    t2.join();
 
    std::cout << "acc1: " << acc1.num_things << "\n"
                 "acc2: " << acc2.num_things << '\n';
}
```

<a name="1_31_threads-1-3"></a>
## Making a Thread Wait (Synchronization)

<a name="1_31_threads-1-3-1"></a>
### Making a Thread Wait **Unconditionally** (Sleep)

-  `std::this_thread::sleep_for` puts the thread to sleep for a certain duration.
- The thread resumes execution after the sleep time expires.
```cpp
void worker() {
    std::cout << "Thread sleeping for 2 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread woke up!\n";
}
```

-  `std::this_thread::sleep_until` puts the thread to sleep until some given time (e.g., 3 seconds from now).
- Useful for scheduling tasks at specific times.
```cpp
void worker() {
    auto wakeup_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    std::cout << "Thread sleeping until a specific time...\n";
    std::this_thread::sleep_until(wakeup_time);
    std::cout << "Thread woke up!\n";
}
```

<a name="1_31_threads-1-3-2"></a>
###  Making a Thread Wait Conditionally (`std::condition_variable`)

- A thread can be made to wait until being notified.
- Upon receiving the notification (wakeup call) the thread can optionally check some condition to effectively wakeup or continue waiting.
- Useful when one thread depends on another to produce data.
- Basic mechanism for synchronization based on a `std::condition_variable`:
	- The worker (consumer) 
		1. Acquires a `std::unique_lock` on the mutex used to protect the shared variable.
		2. Calls `wait` on the `std::condition_variable` which
			- atomically releases the mutex 
			- suspends thread execution until the condition variable is notified
		3. Upon notification, atomically re-acquires the mutex lock and resumes execution.
		
		or alternatively,
		
		2. Calls `wait` on the `std::condition_variable` with a boolean predicate (condition)
		3. Upon notification, **if** the predicate is satisfied, atomically re-acquires the mutex lock and resumes execution, or **else** continues waiting for the next notification.
	- The Signeller (producer)
		1. Acquires a std::mutex (typically via `std::lock_guard`).
		2. Modify the shared variable while the lock is owned.
		3. Call `notify_one` or `notify_all` on the `std::condition_variable` to wakeup one or all waiting threads.

```cpp
#include <iostream>
#include <thread>
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Worker waiting for signal...\n";
    cv.wait(lock, [] { return ready; }); // Wait until ready == true
    std::cout << "Worker received signal, resuming execution!\n";
}

void signal() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    std::cout << "Signaling worker to continue...\n";
    cv.notify_one(); // Wake up the waiting thread
}

int main() {
    std::thread t1(worker);
    std::thread t2(signal);
    
    t1.join();
    t2.join();
    return 0;
}
```

<a name="1_31_threads-1-4"></a>
## Atomic Operations (`std::atomic`)

- Ensures operations on shared variables are performed atomically without locking.

```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
    
    std::cout << "Final Counter: " << counter.load() << std::endl;
    return 0;
}
```


<a name="1_31_threads-1-5"></a>
## Parallel Algorithms (`std::execution`, C++17) 

- Allows parallel execution of standard algorithms.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(std::execution::par, numbers.begin(), numbers.end(), [](int &n) {
        n *= 2;
    });

    for (int n : numbers) std::cout << n << " ";
    return 0;
}
```
- `std::execution::par` enables parallel execution.
- Boosts performance in large datasets.


<a name="1_31_threads-1-6"></a>
## See more

[Concurrency Support Library](https://en.cppreference.com/w/cpp/thread)

---
[[⇦ Previous](1_30_algorithms_idx.md)]		[[Next  ⇨](1_32_coroutines_idx.md)]		[[Index ⇧](index.md#1_31_threads_idx.md)]
