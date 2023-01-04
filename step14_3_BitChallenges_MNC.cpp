#include <iostream>
using namespace std;
#include <climits>


int getBit(int element,int pos){
    return ((element & 1<<pos) != 0);
}


// Write a program to find a unique number in an array where all numbers except one are present twice
int solve1(){
    int match;
    bool bool1;
    int n = 7;
    int arr[n] = {2,4,6,9,4,6,2};

    // Brute-Force Approach
    // for (int i = 0; i < n; i++)
    // {
    //     bool1 = false;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         // if(i != j && arr[i] == arr[j]){
    //         if(arr[i] == arr[j]){
    //             bool1 = true;
    //             break;
    //         }
    //     }

    //     if(!bool1){
    //         match = arr[i];
    //         break;
    //     }   
    // }
    

    // With Time-Complexity Optimized;
    // int mx = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     mx = max(arr[i],mx);
    // }

    // int indexArr[mx++];

    // for (int j = 0; j < mx; j++)
    // {
    //     indexArr[j] = 0;
    // }
    
    // for (int k = 0; k < n; k++)
    // {
    //     indexArr[arr[k]] += 1;
    // }

    // for (int z = 0; z < mx; z++)
    // {
    //     if(indexArr[z] == 1){
    //         match = z;
    //         break;
    //     }
    // }


    // With Bit-Manipulation
    // for (int i = 0; i < n; i++)
    // {
    //     bool1 = false;
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if((arr[i] ^ arr[j]) == 0){
    //             // cout << arr[i] << " ";
    //             bool1 = true;
    //             break;
    //         }
    //     }
    //     if(!bool1){
    //         match = arr[i];
    //         break;
    //     }
    // }

    // return match;

    // Efficient-way
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }   

    return xorsum;
    
};

// Write a program to find 2 unique numbers in an array where all numbers except two, are present twice.
void solve2(){
    int n = 8;
    int arr[n] = {2,4,6,7,4,5,6,2};

    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    cout << xorsum << endl;

    int setBit = 0;
    int count = 0;
    // while (setBit != 1)
    while (1)
    {
        setBit = (xorsum >> count) & 1;
        // cout << "SetBit: " << setBit << endl; 
        // cout << "count: " << count << endl;
        if(setBit == 1){
            break;
        }
        count++; 
    }
    // cout << count;

    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if(getBit(arr[i],count)){
            newxor = newxor ^ arr[i];
        }
    }
    
    cout << "First unique number is: " << newxor << endl;

    cout << "Second unique number is: " << (newxor ^ xorsum) << endl;

}



int main(){
int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": ";
        solve2();
        // cout << endl << solve2() << endl;
        // solve3();
    }
    return 0;
}