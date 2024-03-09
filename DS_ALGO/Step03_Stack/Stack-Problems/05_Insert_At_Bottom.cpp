#include<iostream>
#include<stack>
using namespace std;


void Insert_At_Bottom(stack<int> S,int data){
    if(S.empty()){
        
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

    printStack(S);

    return 0;
}