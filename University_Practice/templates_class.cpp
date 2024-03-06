#include<iostream>
using namespace std;

template <class T>
class myclass{
    public:
    myclass(T x){
        cout << "My class is running " << x << endl;
    }
};

int main(){

    myclass <int>mc1(454);
    myclass <char>mc2('h');
    return 0;
}