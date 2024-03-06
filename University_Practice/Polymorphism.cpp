#include<iostream>
using namespace std;

class Geeks{
	public:
		void func(int x){
			cout << "value of x is: " << x << endl;
		}
		
		void func(double x){
			cout << "value of double is: " << x << endl;
		}
		
		void func(int x, int y){
			cout << "value of x and y is : " << x << " , " << y << endl;
		}
};

class Test {
	public:
		int num;
	public:
		Test(){
			num = 8;
		}
		
	void operator ++(){
		num = num+5;
	}
	
	void Print(){
		cout << "The Count is : " << num << endl;
	}
};

class Parent{
	public:
		void GeeksforGeeks(){
			cout << "This is Geeks from Parent Class" << endl;
		}
};

class Child : public Parent{
	public:
		void GeeksforGeeks(){
			cout << "This is Geeks from Child Class" << endl;
		}
};

class virtual_Parent{
    public:
		virtual void GeeksforGeeks(){
			cout << "This is virtual Geeks from Parent Class" << endl;
		}
};

class virtual_Child : public virtual_Parent{
	public:
		void GeeksforGeeks(){
			cout << "This is virtual Geeks from Child Class" << endl;
		}
};


int main(){
	
	 // 1. Compile-time Polymorphism(Static)
	 	 
//		 a. Fucntion Overloading
	Geeks geeks;
	geeks.func(5);
	geeks.func(5.64);
	geeks.func(5,64);
	
	// b. Operator Overloading
	Test test;
	cout << "num value is: " << test.num << endl;
	++test;
	test.Print();
	
	// 2. Run-time Polymorhpism(Dynamic)
    //		a. Function Overriding

	Parent Base;
	Child derived;
	derived.GeeksforGeeks();
	Base.GeeksforGeeks();
	// Accessing Parent Geeks_Function() from derived
	derived.Parent::GeeksforGeeks();

    cout << endl << endl;
    //		b. Virtual Function
    virtual_Parent vir_parent;
    virtual_Child vir_child;

    virtual_Parent* vir_parent1 = &vir_child;

    vir_child.GeeksforGeeks();
    vir_parent.GeeksforGeeks();
    // Access child class from base class
    vir_parent1->GeeksforGeeks();

	
	return 0;
}
