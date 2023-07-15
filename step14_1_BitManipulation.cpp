#include <iostream>
// #include <cstdlib>
using namespace std;



int getBit(int a,int pos){
    return ((a&(1<<pos)) != 0);
}

int setBit(int a,int pos){
    return ((a | (1<<pos)));
}

int clearBit(int a,int pos){
    return (a & (~(1<<pos)));
}

int updateBit(int a,int pos){
    int mask = (a & (~(1<<pos))); // clearing the bit
    return (mask | (1<<pos)); // updating the bit
}

// 100 | 010 == 110 == 6


int main(){

    int a,pos;
    srand((unsigned) time(NULL));
    cin >> a >> pos;
    cout << getBit(a,pos) << endl;
    cout << setBit(a,pos) << endl;
    cout << clearBit(a,pos) << endl;
    cout << updateBit(a,pos) << endl; // rand() function gives number between 0 and 2

    return 0;
}