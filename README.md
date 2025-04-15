# Deploying Program
1. Go to Makefile
2. Change the `SRC` tag to be whatever file you want to compile (e.g. `SRC = src/namespace.cpp`)
3. Open up terminal, run `make`
4. Run executable via `./main`
5. Before running a different program, run `make clean` to remove the executable file

## Why `using namespace std` is Considered Bad Practice
By including that, we are including ALL members within `std`. If you try to create your own function and given it the same name already present in `std namespace`, that can lead
to more collisions and ambiguity.

For small scale programs, it's okay. Just something to note for large scale projects.

## Mutexes
What is the difference between `lock_guard()` and `unique_lock()`

### Lock Guard
Locks your critical section in the same line where you create it + unlocks the code (**critical section**) automatically once the code is out of scope
* Also means you cannot unlock it manually
* Makes sure that the code is released properly - even the application catches an exception
Used when you want to lock a short, well-defined block of code

### Unique Lock
Required to unlock **manually** -> can lead to huge errors!
* Main advantage is that you can delay locking
