#include<iostream>
using namespace std;
/*
Polymorphism ---> Poly:Many && Morphism:Forms

Polymorphism can be of two types:
    1. Compile-type Polymorphism(Function Overloading,Parameter Overloading)
    2. Run-time Polymorphism (Function Over-Riding)
*/


class A{
    public:
    int real;
    int imag;

    A(int r=0,int i=0){
        real = r;
        imag = i;
    }

    // In Function Overloading, (Amount of function parameter) must be different or (Data type of parameter be different)


    // void print(int n,char check){ // Valid
    void print(char n){ // Valid
    // void print(int n){ //Not Valid
        cout << n << endl;
    }

    int print(int n){
        cout << n << endl;
        return n;
    }


    // Operator Overloading
    A operator+ (A const & upper){
        A sub;
        sub.real = real + upper.real;
        sub.imag = imag + upper.imag;
        return sub;
    }

    void printComplex(){
        cout << real << " + " << imag << "i" << endl;
    }

    virtual void Speaking(){
        cout << "Hello there, I am A speaking" << endl; 
    }
};

    // Run-time Polymorphism(Only achieved by Inheritance)
    // 1. Parent and Child class has same function name
    // 2. Parent and Child class has same number of parameter of functions


    class B : public A{

        // In parent class "Speaking()" is also available, but through RUN-TIME POLYMORPHISM, we can change its implementataion
        public:
        void Speaking(){
            cout << "Hello there, I am B speaking" << endl;
        }
    };



int main(){
    // A obj(5,3);
    // obj.print(5);
    // obj.print('A');

    A complex1(23,5),complex2(234,43);
    A complexSum = complex1 + complex2;
    complexSum.printComplex();

    A a;
    a.Speaking();

    B b;
    b.Speaking();

    // Want to access Speaking() of "A" from "b" object: With "SRO"(Scope Resolution Operator)
    b.A::Speaking();

    // Want to access Speaking() of "B" from "a" object: With "Pointers" and "Virtual Class"
    A *p;
    p = &b;
    p->Speaking();


    return 0;
}