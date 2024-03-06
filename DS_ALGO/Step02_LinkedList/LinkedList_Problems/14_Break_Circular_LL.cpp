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

int len(Node* tail){
     if(tail == NULL){
        return 0;
    }


    Node* temp = tail;
    int count = 0;

    do{
        tail = tail->next;
        count++;
    }while(tail != temp);
    return count;
}

Node* middle(Node* tail){
    if(tail == NULL || tail->next == NULL || tail->next->next == NULL){
        return tail;
    }

    Node* fast = tail->next;
    Node* slow = tail;

    if(len(tail)%2==0){
        fast=tail->next->next;
    }
        while(fast!=tail && fast->next != tail){
            fast=fast->next->next;
            slow = slow->next;
        }
    return slow;
}


void Circular_two_halves(Node* &ll1,Node* &ll2,Node* original){
    // first method
    if(original == NULL){
        return;
    }

    Node* mid = middle(original);

    ll1 = original;
    ll2 = mid->next;
    mid->next = original;

    Node* temp = ll2;
    while(temp->next!=original){
        temp=temp->next;
    }
    temp->next = ll2;
    
}


int main(){
    Node* tail = NULL;
    insertAtPos(tail,0,1);


    insertBeforeStart(tail,44);
    insertBeforeStart(tail,11);
    insertAfterStart(tail,22);
    insertAfterStart(tail,12);
    insertAfterStart(tail,26);
    insertAfterStart(tail,82);
    insertAtPos(tail,22,33);
    insertAtPos(tail,44,55);
    // deleteNode(tail,33);
    // deleting tail
    // deleteNode(tail,1);
    print(tail);

    Node* Circular1 = NULL;
    Node* Circular2 = NULL;
    // Break into two Circular halve linkedlist
    Circular_two_halves(Circular1,Circular2,tail);
    print(Circular1);
    print(Circular2);
    cout << "Tail is at : " << tail->data << endl;
    cout << "tail next is " << tail->next->data << endl;
    return 0;
}