#include<iostream>
using namespace std;

class A{
    public:
    void print(){
        cout << "I am A" << endl;
    }
};

class B{
    public:
    void print(){
        cout << "I am B" << endl;
    }
};

class Mix:public A,public B{
    public:
};


int main(){
    Mix mix;
    // mix.print(); // Here it gives error, because (print() method) includes in both parent classes, so compiler gets ambiguity.
    mix.A::print(); // We have to use (::)--> Scope Resolution Operator
    mix.B::print();


    return 0;
}