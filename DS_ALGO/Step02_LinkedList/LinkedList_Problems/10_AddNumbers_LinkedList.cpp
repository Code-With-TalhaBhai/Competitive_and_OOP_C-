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
    if(tail!=NULL){
    tail->next = temp;
    }

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

Node* reverse(Node* head){
    if(head->next == NULL){
        return head;
    }

    Node* temp_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp_head;
}

// Approach1->My own solution
Node* add_number_linkedlist1(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* temp = NULL;

    int sum1=0,sum2=0;
    while(temp1 != NULL || temp2 != NULL){
        if(temp1!=NULL){
            sum1 = (sum1*10)+temp1->data;
            temp1 = temp1->next;
        }
        else if(temp2!=NULL){
            sum2 = (sum2*10)+temp2->data;
            temp2 = temp2->next;
        }
    }

    int total = sum1+sum2;
    Node* temp_head = NULL;
    while(total>0){
        int data_to_add = total % 10;
        temp = new Node(data_to_add);
        temp->next = temp_head;
        temp_head = temp;
        total /= 10;
    }

    // cout << sum1 << " " << sum2 << endl;
    return temp;
}


Node* add(Node* head1,Node* head2){
    int carry = 0;
    int sum = 0;
    Node* temp_tail = NULL;
    Node* temp_head = temp_tail;

    int i = 0;
    while(head1 !=NULL || head2 != NULL){
        if(head1==NULL){
            // cout << "works1" << endl;
            sum = head2->data + carry;
            head2=head2->next;
        }
        else if(head2==NULL){
            sum = head1->data + carry;
            head1=head1->next;
        }
        else{
            // cout << "works end" << endl;
            sum = head1->data + head2->data + carry;
            head1=head1->next;
            head2=head2->next;
        }
        carry = sum/10;
        int node_to_add = sum%10;
        insert_At_Tail(temp_tail,node_to_add);
        if(i==0){
            temp_head = temp_tail;
        }
        if(head1==NULL && head2 == NULL && carry > 0){
            insert_At_Tail(temp_tail,carry);
        }
        i++;
    }
    return temp_head;
}

// Babbar Sir solution
Node* add_number_linkedlist2(Node* head1,Node* head2){

    Node* temp1 = reverse(head1);
    Node* temp2 = reverse(head2);

    Node* added_linkedlist = add(temp1,temp2);
    Node* final_linkedlist = reverse(added_linkedlist);
    return final_linkedlist;
}



int main(){

    // 4 3 2 5 6 7
    Node* n1 = new Node(7);
    Node* head1 = n1;
    insertAtHead(head1,6);
    insertAtHead(head1,5);
    insertAtHead(head1,2);
    insertAtHead(head1,3);
    insertAtHead(head1,4);
    print(head1);


    // 5 7 9 9 9 8 5 5 3 9 2 9 8 7
    // Node* n2 = new Node(9);
    // Node* head2 = n2;
    // // insertAtHead(head2,4);
    // insertAtHead(head2,2);
    // print(head2);

    Node* n2 = new Node(7);
    Node* head2 = n2;
    insertAtHead(head2,8);
    insertAtHead(head2,9);
    insertAtHead(head2,2);
    insertAtHead(head2,9);
    print(head2);
   
    // Approach1->My own solution
    cout << "Solved by my own approach" << endl;
    Node* added_linkedlist1 = add_number_linkedlist1(head1,head2);
    print(added_linkedlist1);

    cout << "Solved by my geeks_for_geeks approach" << endl;
    Node* added_linkedlist2 = add_number_linkedlist2(head1,head2);
    print(added_linkedlist2);


   return 0;
}