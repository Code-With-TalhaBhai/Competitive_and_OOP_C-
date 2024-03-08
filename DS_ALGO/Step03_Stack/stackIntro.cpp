#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int top;
        int size;
    Stack(int size){
        this->top = -1;
        this->size = size++;
        arr = new int[size];
        cout << "Constructor Done" << endl;
    }

    push(int data){
        top++;
        arr[top] = data;
        // cout << this->top << endl;
    }

    pop(){
        delete *arr[top]; 
    }

    print(){
        int iter = top;
        while(iter>=0){
            cout << this->arr[iter] << endl;
            iter--;
        }
    }
};


int main(){
    Stack S(4);

    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    
    S.print();

    return 0;
}