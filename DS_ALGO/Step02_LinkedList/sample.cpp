#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtTail(int d,Node* &tail){
    Node* temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtMiddle(int d,Node* &head,int pos){
    int cnt = 1;
    Node* temp = new Node(d);
    Node* traverse = head;

    while (cnt < pos-1){
        traverse = traverse->next;
        cnt++;
    }

    temp->prev = traverse;
    traverse->next->prev = traverse;
    temp->next = traverse->next;
    traverse->next = temp;
    

    // while (cnt < pos){
    //     traverse = traverse->next;
    //     cnt++;
    // }
    // traverse->prev->next = temp;
    // traverse->prev = temp;
    // temp->prev = traverse->prev;
    // temp->next = traverse;

}


void insertAtHead(int d,Node* &head){
    Node* temp = new Node(d);

    head->prev = temp;
    temp->next = head;
    head = temp;
}

void deleteNode(Node* &head,int pos){
    Node* traverse = head;
    int cnt = 1;

    while(cnt < pos-1){
        traverse = traverse->next;
        cnt++;
    }

    traverse->next = traverse->next->next;
    traverse->next->prev = traverse;
}



int main(){

    Node* n1 = new Node(40);
    Node* head = n1;
    Node* tail = n1;

 
    insertAtTail(50,tail);
    insertAtTail(60,tail);
    insertAtTail(70,tail);
    insertAtTail(90,tail);
    insertAtHead(10,head);
    insertAtMiddle(20,head,2);
    insertAtMiddle(30,head,3);
    insertAtMiddle(543,head,5);
    print(head);
    deleteNode(head,5);
    print(head);

    return 0;
}