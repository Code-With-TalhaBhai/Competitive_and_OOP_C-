#include<iostream>
using namespace std;
#define PI 3.14159

// Write a program to implement a clas called Rectange that has private member variable for length and width. Include memeber functions to calculate the circle's area and perimeter
class Rectange{
    private:
        int length = 23;
    
    public:
        int area(){
            cout << "The area of circle is: " << PI*(radius^2) << endl;
        }
        int circumference(){
            cout << "The circumference of circle is: " << 2*PI*radius << endl;
        }

};


int main(){

    Circle circle;
    circle.area();
    circle.circumference();
    return 0;
}