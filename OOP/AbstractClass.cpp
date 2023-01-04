#include <iostream>
using namespace std;

// Abstract Class is a class which has atleast one Pure virtual function.

// Pure virtual: Pure Virtual Functions are the ones who
//  doesn't have its body in the Base class and its body is must defined in 
//  derived class otherwise it gives error  

// Abstract Class(At-least one virtual function required to make it abstract)
class Vegetable{
    // Pure Virtual Function 
    virtual void color() = 0;
    // Pure Virtual Function 
    virtual int kg() = 0;
};

class Carrot:public Vegetable{
    public:
        void color(){
            cout << "Red" << endl;
        }

        int kg(){
            return 7;
        }
};



int main(){

    Carrot carr;
    carr.color();
    cout << "Carrot is " << carr.kg() << " kg" << endl;

    return 0;
}