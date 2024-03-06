#include <iostream>
using namespace std;

// Node class for the child linked list
class ChildNode {
public:
    int data;
    ChildNode* next;

    ChildNode(int data) : data(data), next(nullptr) {}
};

// Node class for the main linked list
class Node {
public:
    int data;
    Node* next;
    ChildNode* child;

    Node(int data) : data(data), next(nullptr), child(new ChildNode(data)) {}
    // Node(int data){
    //     data = data;
    //     this->next = NULL;
    //     this->child = new ChildNode(data);
    // }
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void appendChild(int data, Node* parent) {
        ChildNode* newChild = new ChildNode(data);
        if (parent->child == nullptr) {
            parent->child = newChild;
        } else {
            ChildNode* current = parent->child;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newChild;
        }
    }

};


    void printList(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Main Node: " << current->data << std::endl;
            ChildNode* childCurrent = current->child;
            while (childCurrent != nullptr) {
                std::cout << "Child Node: " << childCurrent->data << std::endl;
                childCurrent = childCurrent->next;
            }
            current = current->next;
            cout << endl;
        }
    }


void print(ChildNode* head){
    ChildNode* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}


ChildNode* flatten_linkedList(Node* head){
    if(head == NULL || head->next == NULL){
        return head->child;
    }

    ChildNode* temp_head = flatten_linkedList(head->next);

    ChildNode* child_head = head->child;   
    ChildNode* ch_node = child_head;   

    if(ch_node->next!=NULL){
        while(ch_node->next!=NULL){
            ch_node = ch_node->next;
        }
        ch_node->next = temp_head;
    }
    return child_head;
}


int main() {
    LinkedList* mainList = new LinkedList();
    mainList->push(1);
    mainList->push(2);
    mainList->push(3);
    mainList->push(4);

    Node* firstNode = mainList->head;
    mainList->appendChild(10, firstNode);
    mainList->appendChild(20, firstNode);

    Node* secondNode = firstNode->next;
    mainList->appendChild(30, secondNode);
    mainList->appendChild(40, secondNode);

    Node* thirdNode = secondNode->next;
    mainList->appendChild(50, thirdNode);
    mainList->appendChild(60, thirdNode);
    mainList->appendChild(70, thirdNode);

    Node* ForthNode = thirdNode->next;
    mainList->appendChild(150, ForthNode);
    mainList->appendChild(530, ForthNode);
    mainList->appendChild(550, ForthNode);



    cout << "Actual LinkedList before flattening" << endl;
    printList(firstNode);

    cout << "LinkedList after flattening" << endl;
    ChildNode* fl_linkedList = flatten_linkedList(firstNode);
    print(fl_linkedList);

    return 0;
}
