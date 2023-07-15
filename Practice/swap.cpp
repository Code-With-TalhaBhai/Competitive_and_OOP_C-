#include<iostream>
using namespace std;


int main(){

    int x = 20;
    int y = 10;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    int temp = x;
    x = y;
    y = temp;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;    

    return 0;
}