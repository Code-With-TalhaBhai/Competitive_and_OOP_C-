#include <iostream>
#include<limits.h>
using namespace std;


// Function to print all subarrays
void solve1(){
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int no = 1;
    // With For Loop
   for (int i = 0; i < len; i++)
   {
    for (int j = i; j < len; j++)
    {
        for (int k = i; k <= j; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
    }      
   }

    // cout << endl;
   
    // With while loop
    // int a,b,c;
    // a = b = c = 0;
    // while (a<len)
    // {
    //     b = a;
    //     while(b<len){
    //         c = a;
    //         while (c<=b)
    //         {
    //          cout << arr[c] << " ";
    //          c++;   
    //         }
    //         b++;
    //         cout << endl;
    //     }
    //     a++;
    // }

}

// Maximum sum of all subArrays
int solve2(){
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int sum = 0; int mx = INT_MIN;

    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = i; j < len; j++)
    //     {   
    //         sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             // cout << arr[k] << " ";
    //             sum += arr[k];
    //         }
    //         mx = max(mx,sum);
    //         // cout << endl;
    //     }
    // }



    // Optimized with two loops instead of three
    // int currsum[len+1];
    // currsum[0] = 0;

    // for (int i = 1; i <= len; i++)
    // {
    //     currsum[i] = currsum[i-1] + arr[i-1];
    // }

    // for (int i = 1; i <= len; i++)
    // {
    //     sum = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //     sum = currsum[i] - currsum[j];
    //     mx = max(sum,mx);
    //     }
    // }
    
    

    // Kandane's Algorithm (More Optimized way)
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        mx = max(sum,mx);
    }
    
    return mx;
}



int kadane(int arr[],int n){
    int sum = 0;
    int mx = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum<0){
            sum = 0;
        }
        mx = max(sum,mx);
    }
    return mx;
}


int solve3(){
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }


    int wrapsome; int nowrapsome;
    nowrapsome = kadane(arr,len);

    int totalsum = 0;
    for (int i = 0; i < len; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }


    // cout << "NoWrapSome: " << nowrapsome << endl;
    // cout << "TotalSum: " << totalsum << endl;
    // wrapsome = totalsum + kadane(arr,len);
    // cout << "WrapTotal: " << wrapsome << endl;

    // cout << max(wrapsome,nowrapsome) << endl;
    

    // cout << nowrapsome << endl;

    return nowrapsome;
}

// Pair Sum Problem: Check if there exists two elements in an array such that their sum is equal to given k
int solve4(){
    int given_num;
    cin >> given_num;
    int len;
    cin >> len;
    int arr[len];
    bool bool1;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    //Brute Force Approach
    // for (int i = 0; i < len-1; i++)
    // {
    //     for (int j = 0; j < len; j++)
    //     {
    //         bool1 = (given_num == arr[i] + arr[j])?true:false;
    //         if(bool1){
    //         cout << i << " " << j;
    //         cout << endl;
    //         return 1;
    //         }
    //     }
    // }


    // More time efficient, Time Complexity of N, but array must be sorted
    int sum;
    int low = 0, high = len-1;
    while (low<high)
    {
        sum = arr[low] + arr[high];
        if(sum < given_num){
            low++;
        }  
        else if(sum > given_num){
            high--;
        } 
        else{
            cout << low << " " << high << endl;
            return 1;
        }   
    }
    

        

    return -1;
}


int main(){

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve1();
        // cout << "Case #" << i << ": " << solve2() << endl;
        // cout << "Case #" << i << ": " << solve3() << endl;
        // cout << "Case #" << i << ": " << solve4() << endl;
        cout << endl;
    }

    // {4,-4,6,-6,10,-11,12}

    return 0;
}