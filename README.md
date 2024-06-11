Explanation

    Raw Pointer:
        We allocate memory for an instance of MyClass using new.
        After using the object, we manually deallocate the memory using delete.
        Forgetting to deallocate the memory or improperly managing the pointer can lead to memory leaks or dangling pointers.

    Smart Pointer:
        We use std::unique_ptr, which automatically manages memory for dynamically allocated objects.
        We use std::make_unique to create an instance of MyClass.
        Memory is automatically deallocated when the std::unique_ptr goes out of scope.
        Smart pointers help prevent memory leaks and dangling pointers by ensuring proper ownership and automatic memory management.

if you get this error:
pointers_example.cpp:35:51: error: no member named 'make_unique' in namespace 'std'
std::unique_ptr<Pointers> smartPtr = std::make_unique<Pointers>(42); // Allocate memory using make_unique

        means you need to to switch to c++14 or c++17
        or else, change this:
        std::unique_ptr<Pointers> smartPtr = std::make_unique<Pointers>(42);
        to this
        std::unique_ptr<Pointers> smartPtr(new Pointers(42));
