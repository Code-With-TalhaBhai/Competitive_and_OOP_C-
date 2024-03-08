#include<iostream>
using namespace std;

class Stack{
    int data;
    Stack* next;

    Stack(int element){
        this->data = element;
        this->next = NULL;
    }
}


int main(){

    Stack S;

    return 0;
}