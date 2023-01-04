#include<iostream>
using namespace std;


// Maximum Arithmetic SubArray Length
int solve1(){
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    
    int mx = -1;
    int pd = arr[1]-arr[0];
    int curr = 2;
    int ans;

    for (int i = 0; i < len; i++)
    {
        if(pd == arr[i]-arr[i-1]){
            curr++;
        }
        else{
            curr = 2;
            pd = arr[i] - arr[i-1];
        }
    mx = max(mx,curr);
    }

    return mx;
};


// Record Breaking Days
int solve2(){
    int len,n;
    cin >> len;
    n = len+1; // As we use i+1, for last element
    int arr[n];
    arr[n] = -1;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    bool bool1;
    int mx = -1;

    // Valid but not optimized time constraint problem
    // for (int i = 0; i < len; i++)
    // {
    //     bool1 = false;
    //     for (int j = i; j > 0; j--)
    //     {
    //         if(arr[i]>arr[j]){
    //             bool1 = true;
    //         }
    //     }
    //     if(arr[i] > arr[i+1] && bool1 == true){
    //         count++;
    //     }
    // }
    

    // Optimized Code
    for (int i = 0; i < len; i++)
    {
        if(arr[i]>arr[i+1] && arr[i]>mx){
            count++;
        }
        mx = max(mx,arr[i]);
    }
    
    return count;
    
}


int main(){
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": " << solve2() << endl;
    }
}