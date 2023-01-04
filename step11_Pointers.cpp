#include <iostream>
using namespace std;

int increment(int *a){
    ++*a;
    cout << *a << endl;
    return *a;
}


int main(){

    int a = 10;
    int b = 23;
    int *ptr;
    ptr = &a;

    int *bptr = &b;

    cout << *ptr << endl;
    cout << *bptr << endl;

    cout << ptr << endl;
    cout << bptr << endl;

    cout << &a << endl;
    cout << &b << endl;
    cout << endl;
    cout << endl;


    // Arithmetic Pointers
    int c = 234;
    int *cptr = &c;

    int d = 532;
    int *dptr = &d;

    cout << cptr << endl;
    cout << cptr++ << endl;
    cout << *cptr + 1 << endl;

    cout << dptr << endl;
    cout << *dptr << endl;

    cout << endl;
    cout << endl;


    // Pointer Arrays -> Iterate over array with pointers
    int arr[6] = {24,43,75,23,57,3};
    // cout << *arr << endl; // gives 0 index
    for (int i = 0; i <= 5; i++)
    {
        cout << *(arr+i) << endl;
    }
    cout << endl;
    cout << endl;
    
    // Pointer-to-Pointer 
    int v = 43242;
    int *vptr = &v;

    int **hptr = &vptr;

    cout << *hptr << endl;
    cout << **hptr << endl;
    cout << *vptr << endl;

    **hptr = 12; // Changing value by double pointer
    cout << v << endl;
    cout << endl;
    cout << endl;

    // Passing pointers to functions
    int w = 5;
    increment(&w);
    cout << w << endl;


    return 0;
}