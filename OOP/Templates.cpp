#include<iostream>
using namespace std;

// Template is used for Dynamic Programming(Dynamic-Typing)

// There are two types of templates
// 1. Function Template
// 2. Class Template


// Function Template
template <class A>
void print(A x,A y){
    cout << x << " " << y << endl;
}


// Class Template
template <class C>

class check{
    public:
    // constructor
    check(C a,C b){
        cout << a << " " << b << endl;
    }
};


int main(){

    print(2,5); // Integer
    print(2.4,2.5); // Float
    print(0,1); // boolean
    print('C','B'); // Character
    print("Hey","There"); // String

    cout << endl << endl;

    check <int>che(532,65/34); // Both data-type should be same
    check <char>chec('I','L');

    return 0;
}