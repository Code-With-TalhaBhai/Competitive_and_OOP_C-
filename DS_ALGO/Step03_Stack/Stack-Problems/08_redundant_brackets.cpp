#include<iostream>
#include<stack>
using namespace std;


void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}





int main(){

    stack<int> S;
    S.push(3);
    S.push(-7);
    S.push(9);
    S.push(-2);
    S.push(5);

    return 0;
}