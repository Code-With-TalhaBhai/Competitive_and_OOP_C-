#include<iostream>
#include<stack>
using namespace std;

stack<int> reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return stack;
    }

    int val = stack.top();
    stack.pop();
    reverseStack(stack);
    stack.push(val);
    return stack;
}


void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}


int main(){

    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    cout << "Before Reverse" << endl;
    printStack(S);
    cout << "After Reverse Recurrsion" << endl;
    printStack(reverseStack(S));

    return 0;
}