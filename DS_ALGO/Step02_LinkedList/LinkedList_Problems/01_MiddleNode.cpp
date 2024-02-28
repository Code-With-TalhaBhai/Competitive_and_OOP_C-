#include<iostream>
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

int getListLength(Node* head){
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }
    return cnt;
}

Node* getMiddleNode(Node* head){
    Node* temp = head;
    int mid_len = (getListLength(head)/2)+1;
    
    while(mid_len>1){
        temp = temp->next;
        mid_len--;
    }
    return temp;
}

Node* optimizedMiddleNode(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    Node* temp_slow = head;
    Node* temp_pro = head->next;

    while(temp_pro != NULL){
        temp_pro = temp_pro->next;
        temp_slow = temp_slow->next;

        if(temp_pro == NULL){
            break;
        }
        temp_pro = temp_pro->next;
    }

    return temp_slow;
}




int main(){

    Node* n1 = new Node(22);

    // cout << n1->data << endl;
    // cout << n1->next << endl;

    Node* head = n1;
    Node* tail = n1;
    print(head);

    // cout << head << " Address: " << &head;

    insertAtHead(head,11);
    print(head);

    insert_At_Tail(tail,44);
    print(head);


    insert_At_Tail(tail,55);
    print(head);

    insert_AT_Middle(head,3,33);
    print(head);

    // Insert AT Start through middle
    insert_AT_Middle(head,0,1);
    print(head);

    // Insert AT END through middle
    insert_AT_Middle(head,7,66,tail);
    print(head);

    // deleteNode(head,3);
    // print(head);

    cout << "The length of the list is: " << getListLength(head) << endl;
    cout << "The middle of the LinkedList is: " << getMiddleNode(head)->data << endl;
    cout << "The Optimized code for middle of the LinkedList is: " << optimizedMiddleNode(head)->data << endl;


    cout << endl << endl;
    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;
    return 0;
}
