#include <iostream>
using namespace std;


int main(){

    int a = 10; // Static Memory
    int *p = new int(); // Heap Memory Allocation
    *p = 10;

    cout << p << endl;
    cout << *p << endl;

    delete(p); //free up space to avoid MEMORY_LEAK. As heap memory couldn't de-Allocate memory automatically as STACK-Memory does.

    // DELETE, above only free up space, but memory address remains, so we can use it or completely delete it.
    p = new int[4];
    cout << p <<  endl;
    cout << *p << endl;

    delete[]p; // Delete Memory(Pointing) Data
    p = NULL; // Clear the pointer of the variable(memory address)

    return 0;
}