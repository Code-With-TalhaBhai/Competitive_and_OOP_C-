#include <iostream>
using namespace std;

int main(){

    string str = "hello";
    // cout << str.find('a') << endl;
    cout << str.length() << endl;
    str.replace(1,1,"");
    cout << str << endl;
    cout << str.length() << endl;

    return 0;
}