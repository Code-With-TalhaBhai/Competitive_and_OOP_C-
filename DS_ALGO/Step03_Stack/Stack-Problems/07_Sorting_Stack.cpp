#include<iostream>
#include<stack>
using namespace std;


void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}


void insert_at_sort(stack<int> &S,int num){
    if(S.empty()){
        S.push(num);
        return ;
    }

    int top = S.top();
    if(top<=num){
        S.push(num);
        return ;
    }
    // It can also be written as :
    // if(S.empty() || S.top()<=num){
    //     S.push(num);
    //     return ;
    // }
    S.pop();
    insert_at_sort(S,num);
    S.push(top);
}


void Sort(stack<int> &S){
    if(S.empty()){
        return ;
    }

    int num = S.top();
    S.pop();

    Sort(S);

    insert_at_sort(S,num);
}



int main(){

    stack<int> S;
    S.push(3);
    S.push(-7);
    S.push(9);
    S.push(-2);
    S.push(5);

    cout << "Before sorting" << endl;
    printStack(S);
    cout << "After Sorting" << endl;
    Sort(S);
    printStack(S);

    return 0;
}