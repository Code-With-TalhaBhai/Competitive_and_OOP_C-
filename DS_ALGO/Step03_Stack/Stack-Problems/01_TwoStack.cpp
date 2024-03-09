#include <bits/stdc++.h> 
using namespace std;


class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
        arr[top1]=-4201019;
        arr[top2]=-4201019;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Atleast empty space available for push
        if(top2-top1>2){
            top1++;
            arr[top1] = num;
        }
        else{
            cout << "Stack overflow for top 1" << endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout << "Stack overflow for top 2" << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            int popped = arr[top1];
            top1--;
            return popped;
        }
        else{
            cout << "Already empty" << endl;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
            if(top2<size){
                int popped = arr[top2];
                top2++;
                return popped;
            }
            else{
                cout << "Top 2 is empty" << endl;
            }
    }

    void peek(){
        if(arr[top1]==-4201019){
            cout << "Top1 is empty" << endl;
        }
        else{
            cout << "top1 is at: " << arr[this->top1] << endl;   
        }
        if(arr[top2]==-4201019){
            cout << "Top2 is empty" << endl;
        }
        else{
            cout << "top2 is at: " << arr[this->top2] << endl;   
        }
    }
};


int main(){

    TwoStack S(6);

    S.push1(9);
    S.push1(2);
    S.push1(7);

    S.push2(5);
    S.push2(3);
    S.push2(4);


    S.push1(1);
    S.push2(2);
    // S.pop1();
    // S.pop1();
    // S.pop1();
    // S.pop1();


    // S.pop2();
    // S.pop2();
    // S.pop2();
    // S.pop2();
    // S.pop2();
    // S.pop2();


    S.peek();    

    return 0;
}