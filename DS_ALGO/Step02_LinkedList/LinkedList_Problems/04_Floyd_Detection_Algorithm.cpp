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

bool Detect_Loop(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }
    Node* temp  = head;
    map<Node*,bool> visited;
    while(temp != NULL){
        if(visited[temp]==true){
            return true;
        }
        else{
            visited[temp]=true;
        }
        temp = temp->next;
    }
    return false;
}

Node* floyd_detection_algo(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
    // while(fast != NULL){ // Both true
        fast = fast->next;
        if(fast != NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}



int main(){

    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    Node* spec = NULL;

    // Making LinkedList which is having a loop
    for(int i=20; i<90; i+=10){
        insert_At_Tail(tail,i);
        if(i == 30){
            spec = tail;
        }
    }
    tail->next = spec;
    // head->next = tail; // For Single Loop testing

    // By simple
    cout << "Simple Loop Detection" << endl;
    if(Detect_Loop(head) == true){
        cout << "It has loop inside it" << endl;
    }
    else{
        cout << "No, loop detected" << endl;
    }

    cout << endl;
    // By Floyd-Detection-Algorithm
    cout << "Loop Detection by Floyd's Detection Algorithm " << endl;
    if(floyd_detection_algo(head) != NULL){
        cout << "It has loop inside it" << endl;
    }
    else{
        cout << "No, loop detected" << endl;
    }

    // print(head);
    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;

    return 0;
}