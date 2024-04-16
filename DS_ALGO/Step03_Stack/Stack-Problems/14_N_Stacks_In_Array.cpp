#include <bits/stdc++.h> 
using namespace std;

// `N`: Number of Stacks
// `S` : Size of Array

// push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
// pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.



class NStack
{
public:

    int *arr;
    int *top;
    int *next;
    int n = 0;
    int freespot=0;
    // Initialize your data structure.
    NStack(int N, int S){
        n = N;
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        int freespot;

        for (int i = 0; i < N; i++)
        {
            top[i] = -1;
        }

    for (int i = 0; i < S; i++)
    {
        next[i] = i+1;
    }
        next[S-1] = -1;
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m){
        if(freespot == -1){
            return false;
        }
        // cout << "freespot" << freespot << endl;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }

// Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m){

        if(top[m-1]==-1){
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot; 
        freespot = index;
        return arr[index];
    }


    int get(){
        for (int i = 0; i < n; i++)
        {
            cout << "top: " << top[i] << " ";
        }
        cout << endl;
    }
};


int main(){


    NStack* stack = new NStack(3,7);

    cout << stack->push(1,10) << endl;
    cout << stack->pop(1) << endl;
    cout << stack->push(1,20) << endl;
    cout << stack->push(2,30) << endl;
    cout << stack->push(2,10) << endl;
    cout << stack->push(2,30) << endl;
    cout << stack->pop(2) << endl;
    cout << stack->push(3,50) << endl;

    // stack->get();

    return 0;
}