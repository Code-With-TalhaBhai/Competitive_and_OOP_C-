#include<iostream>
using namespace std;


class Play {
    public:
        string name;

    ~Play(){
        cout << "Destructor running" << endl;
    }

    Play(){
        cout << "constructor working" << endl;
    }


};


int main(){

    Play P;

    return 0;
}