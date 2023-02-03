#include <iostream>
using namespace std;
#include <math.h>
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


// Find the only non-repeating element in an array where every other element repeats thrice
void solve3(){
    int n = 7;
    int arr[n] = {3,3,5,5,3,5,9};

    int z = 32; //Size of int as we're gonna work with integer array;

    // 1st method
    // int res_arr[z];
    // for (int i = 0; i < z; i++)
    // {
    //     res_arr[i] = 0;
    // }

    // int mod,count;
    // for (int i = 0; i < n; i++)
    // {
    //     count = 0;
    //     // decimal to binary
    //     mod = arr[i];
    //     while(1){
    //         mod /= 2;
    //         count++;
    //         if(mod == 0){
    //         break;
    //         }
    //     }

    //     for (int j = 0; j < count; j++)
    //     {
    //         int bit = getBit(arr[i],j);
    //         res_arr[j] += bit;
    //     }
    // }

    // int power,unique = 0;
    // for (int i = 0; i < z; i++)
    // {
    //     if(res_arr[i] != 0){
    //         power = pow(2,i);
    //         unique += power * (res_arr[i]%3);
    //     }
    // }
    
    // 2nd method
    int unique = 0;
    int sum;
    for (int i = 0; i < z; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if(getBit(arr[j],i)){
                sum++;
            }
        }

        if(sum%3 != 0){
            unique = (unique | (1<<i)); //(Set Bit)
        }
        
    }
    


    cout << "The unique number among thrice is: " << unique << endl;
}


int main(){
int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": ";
        // solve2();
        solve3();
    }
    return 0;
}