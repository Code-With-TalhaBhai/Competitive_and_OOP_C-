#include<iostream>
#include<stack>
using namespace std;

void Insert_At_Bottom(stack<int>& S,int data){
    if(S.empty()){
        S.push(data);
        return ;
    }

    int val = S.top();
    S.pop();
    Insert_At_Bottom(S,data);
    S.push(val);
}


// stack<int> reverseStack(stack<int> &stack) {
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return ;
    }

    int val = stack.top();
    stack.pop();
    reverseStack(stack);
    Insert_At_Bottom(stack,val);
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
    reverseStack(S);
    printStack(S);
    // printStack(reverseStack(S));

    return 0;
}