#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        cout << "Destructor working" << endl;
        int value = this->data;
            if(this->next != NULL){
                delete next;
                next = NULL;
            }
        cout << "Memory is free for value " << value << endl;
    }
};


void insertNode(Node* &tail,int element,int data){
    Node* temp = new Node(data);

    if(tail == NULL){
        tail = temp;
        tail->next = tail;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }   

        temp->next = curr->next;
        curr->next = temp;
    }
}

void printNode(Node* tail){
    // int element = tail->data;
    Node* curr = tail;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != tail);
    cout << endl;
}

void deleteNode(Node* &tail,int element){

    if(tail == NULL){
        cout << "Circular LinkedList is empty" << endl;
    }
    else{
        Node* curr = tail;
        Node* prev = tail;

        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }

        
        if(curr == prev){
            tail = NULL;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){

    Node* tail = NULL;
    insertNode(tail,234,10);
    printNode(tail);
    insertNode(tail,10,20);
    printNode(tail);

    insertNode(tail,20,40);
    printNode(tail);

    insertNode(tail,40, 60);
    printNode(tail);


    // Inserting in Middle
    insertNode(tail,20,30);
    printNode(tail);
    insertNode(tail,40,54643);
    printNode(tail);
    insertNode(tail,40,50);
    printNode(tail);

    cout << "After Delete" << endl;
    deleteNode(tail,54643);
    printNode(tail);

    // delete tail;

    return 0;
}