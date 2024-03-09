#include<iostream>
#include<stack>
using namespace std;


int main(){
    stack<int> S;

    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    cout << "STack top is: " << S.top() << endl;
    // S.print();
    return 0;
}