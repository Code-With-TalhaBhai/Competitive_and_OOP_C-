#include <iostream>
using namespace std;

bool recurrsion1(int arr[],int n){
  
    if(n == 1){
        return true;
    }
    bool boolTask = recurrsion1(arr+1,n-1);
    return ((arr[0] <= arr[1]) && boolTask);
}

void recurrsion2(int n){
    if(n == 1){
        cout << n << endl;
        return;
    }

    // Increasing Order
    // recurrsion2(n-1);
    // cout << n << endl;

    // Decreasing Order
    cout << n << endl;
    recurrsion2(n-1);
}


void recurrsion3(int arr[],int n,int len,int num,bool bool1){

    if(n == len){
        cout << -1;
        return ;
    }


    if((*(arr+n) == num) && !bool1){
        cout << n << " ";
        bool1 = true;
    }


    if(bool1){
        if(*(arr+len) == num){
            cout << len << " ";
            return;
        }
        len--;
    }

    n++;
    recurrsion3(arr,n,len,num,bool1);
};








// Program to check array is sorted or not through recurrsion
bool solve1(){
    int n = 6;
    int arr[n] = {1,2,3,3,5,6};

    return recurrsion1(arr,n);
}


// Write a program to print numbers till n in increasing and decreasing order
void solve2(){
    int n;
    cin >> n;
    recurrsion2(n);
}

// Write a program to print first and last index of the specified element in an array
void solve3(){
    int n = 10;
    int arr[n] = {4,2,1,2,3,3,5,2,7,5}; // Here first index of 2 is (1) and last index of 2 is (5);
    int num;
    cin >> num;
    recurrsion3(arr,0,n-1,num,false);
}

int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;

        // cout << "Case #" << i << ": ";
        // solve2();
        // cout << endl;

        cout << "Case #" << i << ": ";
        solve3();
        cout << endl;
    }

    return 0;
}