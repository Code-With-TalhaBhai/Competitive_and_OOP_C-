#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}


class MinStack{
    public:
    stack<int> org_stack;
    stack<int> m_stack;


    void push(int val){
        if(m_stack.empty() || m_stack.top()>val){
            m_stack.push(val);
        }
        org_stack.push(val);
        // if(m_stack.empty()){
        //     m_stack.push(val);
        // }
        // else{
        //     if(m_stack.top()>val){
        //         m_stack.push(val);
        //     }
        // }
    }
    void pop(){
        int val = org_stack.top();
        org_stack.pop();
        if(m_stack.top()==val){
            m_stack.pop();
        }
    }
    int top(){
        return org_stack.top();
    }
    int min(){
        return m_stack.top();
    }

    void print(){
        cout << "Original Stack" << endl;
        printStack(org_stack);
        cout << "Min Stack" << endl;
        printStack(m_stack);
    }
};




int main(){

    // Time Complexity -> O(1)
    // Space Complexity -> O(n) as we are using two stacks
    MinStack* minStack = new MinStack();
    // MinStack minStack;
    minStack->push(54);
    minStack->push(23);
    minStack->push(2);
    minStack->push(6);
    minStack->push(75);
    minStack->push(7);
    minStack->push(1);
    minStack->push(4);

    cout << "Before Pop" << endl;
    cout << "The stack top is: " << minStack->top() << endl;
    cout << "The stack minimum value is: " << minStack->min() << endl;
    
    minStack->pop();
    minStack->pop();

    cout << "After Pop" << endl;
    cout << "The stack top is: " << minStack->top() << endl;
    cout << "The stack minimum value is: " << minStack->min() << endl;
    
    // minStack.print();
    return 0;
}