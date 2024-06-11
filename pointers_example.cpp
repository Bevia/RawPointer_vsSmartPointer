#include <iostream>
#include <memory>

// Class to hold an integer value
class Pointers {
public:
    Pointers(int value) : value(value) {}

    void display() {
        std::cout << "Value: " << value << std::endl;
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

int main() {
    // Using raw pointers
    {
        Pointers* rawPtr = new Pointers(42); // Allocate memory using new
        rawPtr->display();
        std::cout << "Value accessed via raw pointer: " << rawPtr->getValue() << std::endl;
        delete rawPtr; // Deallocate memory using delete
        // rawPtr is now a dangling pointer
    }

    std::cout << "------------\n";

    // Using smart pointers
    {
        std::unique_ptr<Pointers> smartPtr = std::make_unique<Pointers>(42); // Allocate memory using make_unique
        smartPtr->display();
        std::cout << "Value accessed via smart pointer: " << smartPtr->getValue() << std::endl;
        // Memory is automatically deallocated when smartPtr goes out of scope
    }

    return 0;
}
