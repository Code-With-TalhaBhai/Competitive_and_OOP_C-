#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int d){
        this->data = data;
        this->next = next;
    }
};

void insert_At_Tail(Node* &tail,int d){
   
    Node* temp = new Node(d);

    tail->next = temp;

    tail = temp;
};

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    insert_At_Tail(tail,50);
    insert_At_Tail(tail,60);
    insert_At_Tail(tail,70);
    print(head);

}