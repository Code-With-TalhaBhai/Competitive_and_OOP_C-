#include<iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* prev;
        Node* next;


    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

void insertAtHead(Node* &head,Node* &tail,int data){

    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }



    temp->next = head;
    head->prev = temp;
    head = temp;
}


void insert_at_tail(Node* &tail,int data){
    Node* temp = new Node(data);
    if(tail == NULL){
        tail = temp;
        return ;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insert_at_middle(Node* &head,int pos,int data){
    if(pos <= 1){
        insertAtHead(head,data);
        return ;
    }


    Node* NodeToInsert = new Node(data);
    Node* temp = head;

    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    };

    NodeToInsert->prev = temp;
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert; // Additional for Doubly Linked List
    temp->next = NodeToInsert;

}




int main(){

    // Node* n1 = new Node(11);
    // Node* head = n1;
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    
    insertAtHead(head,tail,1);
    print(head);


    // insert_at_tail(tail,33);
    // print(head);


    // insert_at_middle(head,2,22);
    // print(head);
 
    cout << "Head is at--> " << head->data << " and tail is at--> " << tail->data << endl;
    // cout << "Head is at--> " << head->data << endl;


    return 0;
}