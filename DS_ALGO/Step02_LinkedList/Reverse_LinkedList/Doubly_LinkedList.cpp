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


    // ~Node(){

    //     int val = this->data;
    //     if(next != NULL){
    //         delete next;
    //         next = NULL;
    //     }

    //     cout << "Memory free for node with data" << endl;
    // }

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

void insert_at_middle(Node* &head,Node* &tail,int pos,int data){
    if(pos <= 1){
        insertAtHead(head,tail,data);
        return ;
    }


    Node* NodeToInsert = new Node(data);
    Node* temp = head;

    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    };

    if(temp->next == NULL){
        insert_at_tail(tail,data);
        return ;
    }

    NodeToInsert->prev = temp;
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert; // Additional for Doubly Linked List
    temp->next = NodeToInsert;
}

void DeleteNode(Node* &head,Node* &tail,int pos){
    Node *temp = head;
    if(pos == 1){
        head->next->prev = NULL;
        head = head->next;
        return;
    };
    Node* prev_temp = head;
    int count = 1;
    while (count<pos)
    {
        prev_temp = temp;
        temp = temp->next;
        count++;
    }

    // cout << "address: " << temp->next << endl;
    // cout << "data: " << temp->data << endl;
    prev_temp->next = temp->next;
    delete temp;

    // cout << "address: " << temp->next << endl;
    // cout << "data: " << temp->data << endl;

    if(temp->next == NULL){
        tail = prev_temp;
        delete temp;
        return ;
    }

    temp->next->prev = prev_temp;
    delete temp;
}

Node* reverseRecurrsion(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp_head = reverseRecurrsion(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    head->prev = NULL;
    return temp_head;
}


int main(){

    // Node* n1 = new Node(11);
    // Node* head = n1;
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    
    insertAtHead(head,tail,11);


    insert_at_tail(tail,33);


    insert_at_middle(head,tail,2,22);

    // Insert at FIRST from middle
    insert_at_middle(head,tail,1,1);

    // Inserting at last from middle
    insert_at_middle(head,tail,5,44);

    DeleteNode(head,tail,3);
    print(head);


    // Reverse via Recurrsion
    cout << "WE are reversing doubly LinkedLIst using Recurrsion" << endl;
    Node* reverseList = reverseRecurrsion(head);
    print(reverseList);

 
    // cout << "Head is at--> " << head->data << " and tail is at--> " << tail->data << endl;
    // cout << "Head is at--> " << head->data << endl;


    return 0;
}