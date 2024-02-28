#include<iostream>
#include<map>
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
    // ~Node(){
    //     int value = this->data;

    //     if(this->next != NULL){
    //         delete next;
    //         this->next = NULL;
    //     }


    //     cout << "Memory has freed from " << value << endl;
    // }

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

    tail->next = temp;

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

void remove_duplicates_sorted(Node* head){
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* temp = head;
    while(temp!=NULL){
        if(temp->next != NULL && temp->next->data==temp->data){
            Node* node_to_delete = temp->next;
            temp->next = temp->next->next;
            delete node_to_delete;
        }
        else{
            temp=temp->next;
        }
    }
}


int main(){

    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    Node* spec = NULL;

   for(int i=20; i<90; i+=10){
        insert_At_Tail(tail,i);
        if(i == 30 || i == 50 || i == 70){
            for (int j=0;j<2;j++){
                insert_At_Tail(tail,i);
            }
        }
    }

    cout << "Given LinkedList" << endl;
    print(head);

    cout << "After removing duplicates from sorted LinkedList" << endl;
    remove_duplicates_sorted(head);
    print(head);

    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;

    return 0;
}