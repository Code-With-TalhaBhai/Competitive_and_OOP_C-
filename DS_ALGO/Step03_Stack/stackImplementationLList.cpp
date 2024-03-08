#include<iostream>
using namespace std;

class Stack{
    public:
    int data;
    Stack* next;

    Stack(int element){
        this->data = element;
        this->next = NULL;
    }

    void push(){

    }

    void pop(){

    }

    int peak(){
        
    }

};


int main(){

    Stack* S = new Stack(45);
    cout << S->data << endl;

    return 0;
}