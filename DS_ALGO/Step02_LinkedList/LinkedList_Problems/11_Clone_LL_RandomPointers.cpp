#include<iostream>
using namespace std;

class Node {
        public:
            int data;
            Node *next;
            Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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


void insert_At_Tail(Node* &head,Node* &tail,int d){
   
    Node* temp = new Node(d);
    if(tail==NULL){ // for empty linkedlist
        head = temp;
    }
    else{
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
        insert_At_Tail(head,tail,data);
        return ;
    }

    temp_mid->next = temp->next;
    temp->next = temp_mid;
}


void deleteNode(Node* &head,int pos){
    Node* curr = head;
    if(pos == 0){
        cout << "pos: 0" << endl;
    }
    else{
        Node* prev = NULL;
        int count = 1;
        while(count<pos){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

void printLinkedListWithRandom(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        if(temp->random!=NULL){
            cout << temp->random->data << " ";
        }
        temp = temp->next;
    }  
    cout << endl;
}

Node* cloneLinkedListWithRandom(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* original_head = head;
    Node* clone_tail = NULL;
    Node* clone_head = NULL;  

    while(original_head!=NULL){
        insert_At_Tail(clone_head,clone_tail,original_head->data);
        original_head=original_head->next;
    }

    return clone_head;
}


int main(){

   Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* tail = fifth;

    head->next = second;
    head->random = third;

    second->next = third;
    second->random = fifth;

    third->next = fourth;
    third->random = head;

    fourth->next = fifth;
    fourth->random = second;

    fifth->random = fourth;

    cout << "Original linked list with next pointers: " << endl;
    print(head);

    cout << "Original linked list with random pointers:" << endl;
    printLinkedListWithRandom(head);

    Node* clonedHead = cloneLinkedListWithRandom(head);
    cout << endl << "Cloned linked list with random pointers:" << endl;
    print(clonedHead);
    printLinkedListWithRandom(clonedHead);

    return 0;
}