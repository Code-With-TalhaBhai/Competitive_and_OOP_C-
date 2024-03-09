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
    S.push(11);
    S.push(6);
    S.push(7);
    S.push(54);
    S.push(8);

    

    return 0;
}