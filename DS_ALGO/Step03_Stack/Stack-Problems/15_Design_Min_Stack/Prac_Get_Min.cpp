#include<iostream>
#include<stack>
using namespace std;


int get_min2(stack<int> S,stack<int> ans_stack){
    
    int min = INT32_MAX;
    while (!S.empty())
    {
        int top = S.top();
        if(min>top){
            min = top;
        }
        S.pop();
        ans_stack.push(min);
    }
    return ans_stack.top();
}


int get_min1(stack<int> S,int min=INT16_MAX){
    if(S.empty()){
        return min;
    }

    int top = S.top();
    if(min>top){
        min = top;
    }
    S.pop();
    return get_min1(S,min);
}

int get_min(stack<int> S){

    int min = INT16_MAX;

    while(!S.empty()){
        int top = S.top();
        if(min>top){
            min = top;
        }
        S.pop();
    }
    return min;
}


int main(){

    stack<int> S;
    S.push(23);
    S.push(243);
    S.push(1);
    S.push(53);
    S.push(3);
    S.push(8);


    cout << "The minimum in stack is: " << get_min(S) << endl; // via loop
    cout << "The minimum in stack is: " << get_min1(S) << endl; // via recurrsion
    stack<int> ans_stack;
    cout << "The minimum in stack is: " << get_min2(S,ans_stack) << endl; // via two stacks


    return 0;
}