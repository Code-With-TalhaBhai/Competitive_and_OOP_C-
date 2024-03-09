#include<iostream>
#include<stack>
using namespace std;


stack<int> Insert_At_Bottom(stack<int>& S,int data){
    if(S.empty()){
        S.push(data);
        return S;
    }

    int val = S.top();
    S.pop();
    Insert_At_Bottom(S,data);
    S.push(val);
    return S;
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

    Insert_At_Bottom(S,6);
    Insert_At_Bottom(S,7);
    Insert_At_Bottom(S,8);

    printStack(Insert_At_Bottom(S,9));

    return 0;
}