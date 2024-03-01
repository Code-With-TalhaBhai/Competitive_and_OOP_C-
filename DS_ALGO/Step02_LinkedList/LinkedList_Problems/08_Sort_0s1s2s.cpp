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


Node* sort_0s_1s_2s_using_data(Node* head){
    if(head == NULL){
        return head;
    }

    int countZeros = 0;
    int countOnes = 0;
    int countTwos = 0;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            countZeros++;
        }
        if(temp->data == 1){
            countOnes++;
        }
        if(temp->data == 2){
            countTwos++;
        }
        temp = temp->next;
    }


    temp = head;
    while(temp!=NULL){
        if(countZeros>0){
            temp->data = 0;
            countZeros--;
        }
        else if(countOnes>0){
            temp->data = 1;
            countOnes--;
        }
        else if(countTwos>0){
            temp->data = 2;
            countTwos--;
        }
        else{
            cout << "Not True LinkedList" << endl;
        }
        temp = temp->next;
    }
    return head;
}


Node* sort_0s_1s_2s_using_merge(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* zeroHead = new Node(-5); // Dummy Node
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-5); // Dummy Node
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-5); // Dummy Node
    Node* twoTail = twoHead;


    Node* temp = head;
    while(temp!=NULL){
        int value = temp->data;
        if(value == 0){
            insert_At_Tail(zeroTail,value);
        }
        else if(value == 1){
            insert_At_Tail(oneTail,value);
        }
        else if(value == 2){
            insert_At_Tail(twoTail,value);
        }
        temp=temp->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    // twoTail->next = NULL; // Optional

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

Node* solve_sort(Node* first,Node* second){
    Node* temp1 = first;
    Node* temp2 = second;
    Node* node_to_fit = NULL;

    while(temp1->next != NULL && temp2 != NULL){
        if(temp1->data <= temp2->data && temp1->next->data >= temp2->data){
            node_to_fit = temp2;
            temp2 = temp2->next;
            node_to_fit->next = temp1->next;
            temp1->next = node_to_fit;
        }
        temp1=temp1->next;
    }

    if(temp2!=NULL){
        temp1->next = temp2;
    }

    return first;
}


Node* merge_sorted_linkedlists(Node* head1,Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }


    if(head1->data <= head2->data){
        return solve_sort(head1,head2);
    }
    else if(head1->data > head2->data){
        return solve_sort(head2,head1);
    }

    return NULL;
}


int main(){

    // 1 -> 0 -> 2 -> 1 -> 2
    Node* n = new Node(1);
    Node* head = n;
    Node* tail = n;

    insert_At_Tail(tail,2);
    insert_At_Tail(tail,1);
    insert_At_Tail(tail,2);
    insert_At_Tail(tail,1);
    insert_At_Tail(tail,1);

    cout << "Given LinkedList: ";
    print(head);


    // Node* sorted_using_data = sort_0s_1s_2s_using_data(head);
    // cout << "After sorted linkedlist will be: ";
    // print(sorted_using_data);


    Node* sorted_using_merge = sort_0s_1s_2s_using_merge(head);
    cout << "After sorted using merge linkedlist will be: ";
    print(sorted_using_merge);
    cout << endl << endl;


    Node* n1 = new Node(7);
    Node* head1 = n1;
    insertAtHead(head1,3);
    insertAtHead(head1,1);
    cout << "First Sorted LL: ";
    print(head1);

    Node* n2 = new Node(5);
    Node* head2 = n2;
    insertAtHead(head2,4);
    insertAtHead(head2,2);
    cout << "Second Sorted LL: ";
    print(head2);



    Node* mergeLL = merge_sorted_linkedlists(head1,head2);
    print(mergeLL);

    cout << "Head->" << head->data << " Tail-> " << tail->data << endl;
    return 0;
}