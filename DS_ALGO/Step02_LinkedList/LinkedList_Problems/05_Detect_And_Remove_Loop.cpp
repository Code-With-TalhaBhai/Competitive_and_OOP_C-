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

Node* floyd_detect_node(Node* head){
    if(head == NULL){
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
            break;
        }
    }
    return fast;
}

Node* get_start_node_loop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* intersection = floyd_detect_node(head);

    // slow=head;
    while(intersection != slow){
        intersection=intersection->next;
        slow=slow->next;
    }
    return slow;
}

// Approach-1
void remove_loop1(Node* head){
    if(head == NULL){
        return;
    }

    Node* loopStartNode = get_start_node_loop(head);
    Node* temp = loopStartNode;

    while(temp->next != loopStartNode){
        temp = temp->next;
    }

    temp->next = NULL;
}


// Approach-2
void remove_loop2(Node* head){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    map<Node*,bool> visited;

    while(temp != NULL){
        if(visited[temp->next] == true){
            break;
        }
        else{
            visited[temp] = true;
        }
        temp = temp->next;
    }
    temp->next = NULL;
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
    // tail->next = head; // For single node testing


    // Getting fist Node where the loop starting
    cout << get_start_node_loop(head)->data << endl;
    // cout << floyd_detect_node(head)->data << endl;

    cout << "After removing Loop from LinkedList" << endl;
    remove_loop1(head); // Approach 1
    // remove_loop2(head); // Approach 2


    // Loop in LinkedList can also be removed with `hash-map`

    print(head);
    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;

    return 0;
}