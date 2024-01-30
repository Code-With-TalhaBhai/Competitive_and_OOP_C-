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

Node* reverseList(Node* &head){
// void reverseList(Node* &head){
   
   // For empty or single Node
   if(head == NULL || head->next == NULL){
    return head;
   }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr != NULL)
    {
        // print(head);
       forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward;
    //    head = prev;
    }
    return prev;
}

Node* reverse(Node* prev,Node* &head,Node* forward){
    Node* curr = head;
    if(curr == NULL){
        return prev;
    }

    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    return reverse(prev,curr,forward);
}


Node* recurrsionReverse(Node* &head){
    return reverse(NULL,head,NULL);
}


Node* reverseListSingle(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp_head = reverseListSingle(head->next);

    head->next->next = head;
    head->next = NULL;
    return temp_head;
}


int main(){

    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    insert_At_Tail(tail,20);
    insert_At_Tail(tail,30);
    insert_At_Tail(tail,40);
    print(head);

    // cout << "With Iteration" << endl;
    // Node* reverseLinkedList = reverseList(head);

    // cout << "Via Recurrsion" << endl;
    // Node* reverseLinkedList = recurrsionReverse(head);
    // print(reverseLinkedList);


    cout << "Via Recurrsion single parameter" << endl;
    Node* SingleNodeRecurrsion = reverseListSingle(head);
    print(SingleNodeRecurrsion);


    return 0;
}