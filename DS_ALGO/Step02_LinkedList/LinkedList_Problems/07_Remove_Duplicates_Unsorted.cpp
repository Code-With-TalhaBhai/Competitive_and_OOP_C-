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



void remove_duplicates_unsorted1(Node* head){
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* temp = head;
    Node* traverse = head;

    while(temp!=NULL){
        traverse = temp;
        while(traverse != NULL){
            if(traverse->next!=NULL && temp->data==traverse->next->data){
                traverse->next = traverse->next->next;
            }
            else{
            traverse = traverse->next;
            }
        }
        temp=temp->next;
    }
}

void remove_duplicates_unsorted2(Node* head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    map<int,bool> visited;

    // visited[temp->data] = true;

    while(temp!=NULL){
        // if(temp->next != NULL && visited[temp->data] == true){
        if(temp->next != NULL && visited[temp->next->data] == true){
            temp->next = temp->next->next;
        }
        else{
            visited[temp->data] = true;
            temp = temp->next;
        }
    }
}


int main(){

    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    Node* spec = NULL;

   // Unsorted LinkedList
   insert_At_Tail(tail,20);
   insert_At_Tail(tail,30);
   insert_At_Tail(tail,40);
   insert_At_Tail(tail,50);
   insert_At_Tail(tail,40);
   insert_At_Tail(tail,10);
   insert_At_Tail(tail,50);
   insert_At_Tail(tail,30);
   insert_At_Tail(tail,90);

    cout << "Given LinkedList" << endl;
    print(head);

    cout << "After removing duplicates from sorted LinkedList" << endl;
    // Approach-1 (Time-Complexity of O(n^2))
    remove_duplicates_unsorted1(head);

    // Approach-2 (Time-Complexity of O(n))
    // remove_duplicates_unsorted2(head); // Not completed YET
    // print(head);

    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;

    return 0;
}