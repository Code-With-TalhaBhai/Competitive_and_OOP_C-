#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
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

void reverseList(Node* &head){
    // Node* prev = head;
    // Node* curr = prev->next;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    // cout << curr->data << endl;
    while (curr != NULL)
    {
        // print(head);
       forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
       head = prev;
    }

    // while (curr != NULL)
    // {
    //     head = curr;
    //     head->next = curr;
    //     // prev = curr;
    //     curr->next = curr;
    // }
    

    // while(curr != NULL){
    //     prev = curr;
    //     curr = curr->next;
    //     curr->next = prev;
    // }

   
   

    // while(prev != NULL){
    //     prev->next = curr;
    // }

    // head = prev;

}


int main(){

    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    insert_At_Tail(tail,20);
    insert_At_Tail(tail,30);
    insert_At_Tail(tail,40);
    print(head);

    reverseList(head);
    print(head);


    return 0;
}