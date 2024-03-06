#include<iostream>
using namespace std;

// Abstraction - Abstraction means displaying only essential information and hiding the details.
// Types of Abstraction:

// 1. Data Abstraction - This type only shows the required information about the data and hides the unnecessary data.
//  a. Abstraction using classes
//  b. Abstraction in header files

// 2. Control Abstraction - This type only shows the required information about the implementation and hides unnecessary information.


class Shape{
    public:
       virtual void description() = 0;
};

class Circle : public Shape{
    public:
        void description(){
            cout << "I am circle" << endl;
        }
};

class Triangle : public Shape{
    public:
        void description(){
            cout << "I am Triangle" << endl;
        }
};

int main(){
// Abstract Class
// Sometimes implementation of all functions cannot be provided in a
// base class because we don’t know the implementation. Such a class is
// called an abstract class

// Pure virtual functions are used
// 1. if a function doesn't have any use in the base class
// 2. but the function must be implemented by all its derived 
// classe

    Circle circle;
    Triangle triangle;

    circle.description();
    triangle.description();

    return 0;
}