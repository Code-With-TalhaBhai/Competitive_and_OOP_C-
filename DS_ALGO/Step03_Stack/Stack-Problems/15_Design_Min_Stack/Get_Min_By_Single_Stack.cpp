#include<iostream>
#include<stack>
using namespace std;


class Stack{
    public:
    stack<int> st;
    int mini;

    void push(int data){
        if(st.empty()){
            mini = data;
            st.push(data);
        }

        if(data<mini){
            mini = data;
            int data_to_push = 2*data - mini;
            st.push(data_to_push);
        }
        else{
            st.push(data);
        }
    }

    int pop(){
        if(st.empty()){
            return -1;
        }

        int curr = st.top();
        // cout << "curr is" << curr << endl;
        st.pop();
        if(curr>mini){
            return curr;
        }        
        else{
            int prevMini = mini;
            mini = 2*prevMini - curr;// 2 - 5 = -3 || -3 - 2 = -5 
            return prevMini;
        }
        return curr;
   }

    int top(){
        int curr = st.top();
        if(curr>mini){
            return curr;
        }
        return mini;
    }

    int min(){
        return mini;
    }
};



int main(){

    Stack* S = new Stack();
    S->push(54);
    S->push(5);
    S->push(754);
    S->push(14);
    S->push(3);
    S->push(44);
    S->push(177);

    cout << "Before Pop" << endl;
    cout << "The stack top is: " << S->top() << endl;
    cout << "The stack minimum value is: " << S->min() << endl;

    // cout << "Popped value: " << S->pop() << endl;
    // cout << "Popped value: " << S->pop() << endl;
    S->pop();
    S->pop();
    S->pop();
    S->pop();
    S->pop();
    S->pop();

    cout << "After Pop" << endl;
    cout << "The stack top is: " << S->top() << endl;
    cout << "The stack minimum value is: " << S->min() << endl;

    // int a = -542;
    // cout << a << endl;

    return 0;
}