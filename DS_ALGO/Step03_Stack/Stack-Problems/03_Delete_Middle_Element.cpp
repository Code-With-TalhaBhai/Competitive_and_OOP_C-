#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int getMid(stack<int> s){
    int total = 0;
    while(!s.empty()){
        total++;
        s.pop();
    }
    int mid = total/2;
    if(total%2==1){
        mid++;
    }
    return mid;
}

void deleteMiddleElement(stack<int> &S,int mid,int start){
    int value = S.top();
    S.pop();
    start++;

    if(start >= mid){
        return;
    }

    deleteMiddleElement(S,mid,start);
    S.push(value);
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

    cout << "Before deleting middle" << endl;
    printStack(S);
    // cout << "mid is: " << getMid(S) << endl;
    deleteMiddleElement(S,getMid(S),0);
    cout << "After deleting middle" << endl;
    printStack(S);


    return 0;
}