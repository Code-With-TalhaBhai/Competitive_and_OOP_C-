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
        top1++;
        arr[top1] = num;
    }

    // Push in stack 2.
    void push2(int num) {
        top2--;
        arr[top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        top1--;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        top2--;
    }

    void peek(){
        if(arr[top1]==-4201019){
            cout << "Array1 is empty" << endl;
        }
        else{
            cout << "top1 is at: " << arr[this->top1] << endl;   
        }
        if(arr[top2]==-4201019){
            cout << "Array1 is empty" << endl;
        }
        else{
            cout << "top1 is at: " << arr[this->top2] << endl;   
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

    S.pop1();
    S.pop1();

    S.pop2();
    S.pop2();

    S.peek();    

    return 0;
}