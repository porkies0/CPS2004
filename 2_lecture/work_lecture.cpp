#include <iostream>
using namespace std;

struct RefClass {
    int data;
    RefClass(int d) : data(d) {}
};

struct MyClass {
    int value;
    int anotherValue; // New int field
    RefClass* pointer;
    
    // Initialization
    void init(int v, int anotherV) {
    value = v;
    anotherValue = anotherV;
    pointer = new RefClass(10); // Allocating on the heap
    }

    // Deinitialization
    void deinit() {
    delete pointer; // Deallocate the heap memory
    }
}