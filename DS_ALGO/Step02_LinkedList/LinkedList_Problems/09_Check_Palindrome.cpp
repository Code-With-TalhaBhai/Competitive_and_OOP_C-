#include<iostream>
#include<map>
#include<vector>
#include<cmath>
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

// With Array
// bool check_palidrome1(Node* head){
//     if(head == NULL){
//         return false;
//     }// For empty
//     if(head->next == NULL){
//         return true;
//     }// For single Node

//     int arr[1000];
//     Node* temp = head;
//     int i = 0;
//     while(temp!=NULL){
//         arr[i] = temp->data;
//         temp=temp->next;
//         i++;
//     }
//     --i;


//     int j = 0;
//     while(i>=j){
//         if(arr[j]!=arr[i]){
//             return false;
//         }
//         i--;
//         j++;
//     }

//     return true;
// };


// With Vector
bool check_palidrome1(Node* head){

    if(head == NULL){
        return false;
    }// For empty
    if(head->next == NULL){
        return true;
    }// For single Node

    Node* temp = head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    int i=0,j=arr.size()-1;
   
    while(i<=j){
        if(arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

Node* getMiddleNode1(Node* head){
    Node* temp = head;

    int len = 1;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }

    // cout << "The length of Linkedlist is: " << len << endl;
    // int mid = ceil(double(len)/2);
    int mid = len/2;

    temp = head;
    while(mid<len-1){
        temp=temp->next;
        len--;
    }
    return temp;
}

Node* getMiddleNode2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}


Node* reverse(Node* head){
    if(head->next == NULL){
        return head;
    }    

    Node* temp_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp_head;
}

bool check_palidrome2(Node* head){
     if(head == NULL){
        return false;
    }// For empty
    if(head->next == NULL){
        return true;
    }// For single Node


    // Node* middle = getMiddleNode1(head); //Both ways work
    Node* middle = getMiddleNode2(head); //Both ways work

    Node* half_reverse = reverse(middle->next);
    middle->next = half_reverse;
 
    Node* first_half = head;
    Node* second_half = middle->next;
   
    while(second_half!=NULL){
        if(first_half->data != second_half->data){
            return false;
        }

        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Back to original
    Node* half_reverse_back = reverse(half_reverse);
    middle->next = half_reverse_back;
    return true;
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
   insert_At_Tail(tail,60);
   insert_At_Tail(tail,60);
   insert_At_Tail(tail,50);
   insert_At_Tail(tail,40);
   insert_At_Tail(tail,30);
   insert_At_Tail(tail,20);
   insert_At_Tail(tail,10);

    cout << "Given LinkedList" << endl;
    print(head);

    // First Approach
    if (check_palidrome1(head)){
        cout << "It is palindrome linkedlist" << endl;
    }
    else{
        cout << "It is not palindrom! Not at all!" << endl;
    }

    cout << endl << endl;

    // Approach 2
    if (check_palidrome2(head)){
        cout << "It is palindrome linkedlist with approach 2" << endl;
    }
    else{
        cout << "It is not palindrom! Not at all with approach 2!" << endl;
    }

    print(head);
    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;
    return 0;
}