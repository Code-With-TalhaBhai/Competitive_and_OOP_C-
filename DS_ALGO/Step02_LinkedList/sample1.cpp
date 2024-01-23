#include<iostream>
using namespace std;


// Circular Linked List

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(int d,int element,Node* &tail){
    Node* temp = new Node(d);

    if(tail == NULL){
        temp->next = temp;
        tail = temp;
    }
    else{
        
    }

   

}


int main(){

    Node* node = new Node(10);

    Node* head = node;
    Node* tail = node;

    insertAtTail(10)

    return 0;
}