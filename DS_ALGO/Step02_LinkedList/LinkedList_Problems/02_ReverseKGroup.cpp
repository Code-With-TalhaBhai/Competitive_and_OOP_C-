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

Node* reverse_single_list(Node* head,int k){
    if(k==1 || head == NULL || head->next == NULL){
        return head;
    }

    Node* temp_head = reverse_single_list(head->next,--k);

    head->next->next = head;
    head->next = NULL;
    return temp_head;
}



Node* reverse_k(Node* head,int k){
    if(head == NULL){
        return head;
    }

    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int i = 0;
    while(k>i && curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;    
    }

    Node* temp_head = reverse_k(curr,k);

    head->next = temp_head;
    return prev;
}

Node* rev_grp_recurr(Node* head,int k){
    if(head == NULL){
        return head;
    }

    int i = 0;
    Node* traverse_head = head;
    while(k>i && traverse_head != NULL){
        traverse_head = traverse_head->next;
        i++;
    }

    Node* traversed = reverse_single_list(head,k);
    Node* temp_head = rev_grp_recurr(traverse_head,k);
    
    head->next = temp_head;
    return traversed;
}


int main(){

    Node* n1 = new Node(20);

    Node* head = n1;
    Node* tail = n1;
    print(head);

    // cout << head << " Address: " << &head;

    insertAtHead(head,10);


    insert_At_Tail(tail,40);
    insert_At_Tail(tail,50);
    insert_AT_Middle(head,3,30);
    insert_At_Tail(tail,60);
    insert_At_Tail(tail,70);
    insert_At_Tail(tail,80);
    insert_At_Tail(tail,90);
    print(head);

    cout << endl;

    // Node* single = reverse_single_list(head,25);
    // print(single);

    // Worked
    // Node* reverse_k_group = reverse_k(head,3);
    // print(reverse_k_group);

    // With Recurrsion
    Node* reverse_grp_recurrsion = rev_grp_recurr(head,3);
    print(reverse_grp_recurrsion);
   
    cout << endl;

    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;
    return 0;
}
