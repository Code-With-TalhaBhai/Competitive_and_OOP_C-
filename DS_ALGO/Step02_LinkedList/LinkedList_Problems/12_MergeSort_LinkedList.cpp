#include<iostream>
#include <cstdlib> // for rand() and srand()
using namespace std;

class Node {
        public:
            int data;
            Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    };

    // This destructor does not call automatically because we use "new" keyword for creating object
    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }


        cout << "Memory has freed from " << value << endl;
    }

};

void insertAtHead(Node* &head,int d){

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}


void insert_At_Tail(Node* &tail,int d){
   
    Node* temp = new Node(d);
    if(tail!=NULL){ // for empty linkedlist
        tail->next = temp;
    }
    tail = temp;
};


void insert_AT_Middle(Node* &head,int pos,int data,Node* tail=NULL){ // Optional parameter tail use to insert node at tail

    if(pos == 0){
        insertAtHead(head,data);
        return ;
    }

    Node* temp_mid = new Node(data);

    int cnt = 1;

    Node* temp = head;

    while(cnt<pos-1){
        // temp_head->next = temp_head;
        // cout << cnt;
        temp = temp->next;
        cnt++;
    };

    if(temp->next == NULL){
        insert_At_Tail(tail,data);
        return ;
    }

    temp_mid->next = temp->next;
    temp->next = temp_mid;
}


Node* get_mid(Node* head){
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }

   Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}



Node* solve_sort(Node* first,Node* second){
    Node* final = new Node(-324); // Dummy
    Node* temp = final;

    while(first!=NULL && second!=NULL){
        if(first->data <= second->data){
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else{
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    while(first != NULL){
        temp->next = first;
        temp = first;
        first = first->next;
    }

    while(second != NULL){
        temp->next = second;
        temp = second;
        second = second->next;
    }

    final = final->next;
    return final;
}


Node* merge(Node* left,Node* right){
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data <= right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}

Node* merge_sort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = get_mid(head);


    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = merge_sort(left);
    right = merge_sort(right);

    Node* result = merge(left,right);
    return result;
}


int main(){

    Node* n1 = new Node(22);
    Node* head = n1;
    Node* tail = n1;

    insert_At_Tail(tail,14);
    insert_At_Tail(tail,74);
    insert_At_Tail(tail,3);
    insert_At_Tail(tail,4);
    insert_At_Tail(tail,54);
    insert_At_Tail(tail,34);
    insert_At_Tail(tail,65);
    insert_At_Tail(tail,35);
    cout << "Without sorting" << endl;
    print(head);
    cout << "With Sorting" << endl;
    Node* merge_sort_result = merge_sort(head);
    print(merge_sort_result);


    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;
    return 0;
}