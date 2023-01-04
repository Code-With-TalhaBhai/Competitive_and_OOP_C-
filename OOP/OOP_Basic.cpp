#include <iostream>
using namespace std;

class Teacher{
        int salary = 786;
        public: // By Default, Class properties are private
            string name;
            int age;
            bool married;

        // Default Constructor
        Teacher(){
            cout << "Default Constructor running" << endl;
        }

        // Constructor function for not to get values one-by-one
        // Parameter Constructor

        // Without (this) keyword --> Difficult constructor input_name and Class Properties_name should be different
        // Teacher(int c_salary,string c_name,int c_age,bool c_married){
        //     salary = c_salary;
        //     name = c_name;
        //     age = c_age;
        //     married = c_married;
        // }

        // With (this) keyword easily but use (->) it, instead of dot(.) operator
        Teacher(int salary,string name,int age,bool married){
            this->salary = salary;
            this->name = name;
            this->age = age;
            this->married = married;
        }


        void print(){
            cout << name << endl;
            cout << age << endl;
            cout << married << endl;
            cout << salary << endl;
        }
};


int main(){

    // Without Constructor and With Static Allocation
    Teacher T;
    T.name = "Sir Rauf";
    T.age = 53;
    T.married = true;
    T.print();
    cout << endl;


    // Dynamic Allocation
    Teacher *b = new Teacher();
    (*b).name = "Sir Naeem Ashraf";
    (*b).age = 28;
    (*b).married = 'M';

    // Two ways to call
    // 1st method
    cout << endl << endl;
    cout << "Dynamic Name: " << (*b).name << endl;
    cout << "Dynamic Age: " << (*b).age << endl;
    (*b).print();
    cout << endl;
    cout << endl;

    // 2nd method
    cout << b->married << endl;
    b->print();
    cout << endl;


    // With Paramterized Constructor ---> Constructor call By-default
    Teacher T1(23432,"Sir Asim",25,false);
    T1.print();
    cout << endl;

    // Teacher T2(432423,"Sir Zia",64,false);
    // T2.print();
    // cout << endl;


    // With Default Constructor
    Teacher T3;

    return 0;
}