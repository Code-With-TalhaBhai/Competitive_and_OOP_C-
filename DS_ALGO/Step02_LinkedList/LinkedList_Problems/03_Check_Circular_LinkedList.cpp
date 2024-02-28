#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    };

    // This destructor does not call automatically because we use "new" keyword for creating object
    ~Node(){
        // cout << "Destructor running for: " << this->data << " and its address is: " << this->next << endl;
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        };
        cout << "Memory is free for value " << value << endl;
    }

};

void insertBeforeStart(Node* &tail,int d){
    Node* temp = new Node(d);
    temp->next = tail->next;
    tail->next = temp;
};

void print(Node* tail){

    if(tail == NULL){
        cout << "Linked list is empty" << endl;
        return ;
    }

    Node* temp = tail;

    // Difficult method
    // cout << tail->data << endl;
    // while(tail->next != temp){
    //     tail = tail->next;
    //     cout << tail->data << endl;
    // }

    // Easy Method with do-while looop
    // Using do-while, so it at-least runs one time, maybe Single Node available, and pointing to itself
    do{
        cout << tail->data << " ";
        tail = tail->next;
    }while(tail != temp);
    cout << endl;
};

void insertAfterStart(Node* &tail,int d){
    Node* temp = new Node(d);

    temp->next = tail->next->next;
    tail->next->next = temp;

}


void insertAtPos(Node* &tail,int element,int d){
    Node* temp = new Node(d);
    
    if(tail == NULL){
        tail = temp;
        tail->next = tail;
    }
    else{

        Node* curr = tail;
        while(element != curr->data){
            curr = curr->next;
        };

    // cout << "element " << tail->data << endl;
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int element){
    if(tail == NULL){
        cout << "LinkedList is empty" << endl; 
    }
    else{    
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        };

        prev->next = curr->next; 

        // For Single Node Linked list
        if(curr == prev){
            tail = NULL;
        }

//      For Two or More Node Linked list
        else if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool Check_Circular_LinkedList(Node* head){
    if(head == NULL){
        return true;
    }
    Node* temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;    
}


int main(){
    Node* tail = NULL;
    insertAtPos(tail,0,1);


    insertBeforeStart(tail,44);
    print(tail);
    insertBeforeStart(tail,11);
    print(tail);


    insertAfterStart(tail,22);
    // Must print 1 11 22 44 
    print(tail);

    // Inserting after element 22
    insertAtPos(tail,22,33);
    print(tail);

    insertAtPos(tail,44,55);
    print(tail);


    bool checkCicular = Check_Circular_LinkedList(tail);
    if(checkCicular){
        cout << "It is definitely circular LinkedList" << endl;
    }
    else{
        cout << "It is not circular" << endl;
    }

    // When deleting single node tail this not work
    cout << "Tail is at : " << tail->data << endl;
    cout << "tail address is " << tail->next << endl;

    delete tail;

    return 0;
}