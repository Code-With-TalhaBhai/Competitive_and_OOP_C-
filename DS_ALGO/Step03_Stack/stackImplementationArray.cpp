#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        // if(size-1>top){
            if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(top>=0){
            size--;
            top--;
        }
        else{
            cout << "Stack underflow" << endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isempty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }

};


int main(){

    Stack S(2);

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);

    S.pop();
    S.pop();

    cout << "Is stack empty: " << S.isempty() << endl;

    cout << S.peek() << endl;

    return 0;
}