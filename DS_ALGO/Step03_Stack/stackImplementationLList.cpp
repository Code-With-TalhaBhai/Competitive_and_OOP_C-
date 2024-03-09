#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int element){
        this->data = element;
        this->next = NULL;
    }
};


class Stack{
    public:
        Node* top;

    Stack(){
        top = NULL;
    }

    void push(int data){
        Node* temp = new Node(data);
        if(top!=NULL){
            temp->next = top;
        }
        top = temp;
    }

    void pop(){
        if(top==NULL){
            cout << "Stack Underflow" << endl;
        }
        else{
            Node* temp = top;
            top=top->next;
            delete temp;
        }
    }


    int peak(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isempty(){
        if(top!=NULL){
            return false;
        }
        else{
            return true;
        }
    }

};


int main(){

    Stack S;
    S.push(45);
    S.push(55);
    S.push(4);
    S.push(5);
    S.push(64);
    S.push(65);

    S.pop();
    S.pop();
    // S.pop();
    // S.pop();

    cout << S.peak() << endl;
    cout << "Stack is empty: " << S.isempty() << endl;
    return 0;
}