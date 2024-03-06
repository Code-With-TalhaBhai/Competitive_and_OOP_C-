#include<iostream>
using namespace std;

template<typename U>

int add(U a,U b){
    return a + b;
}

int main(){

    cout << add<int>(46,7645) << endl;
    cout << add<char>('g','h') << endl;

    return 0;
}