#include <iostream>
#include <climits>
using namespace std;

// Find First occurence which is repeating
int solve1(){
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // Not Optimized Code
    // for (int index = 0; index < len; index++)
    // {
    //     for (int j = index+1; j < len; j++)
    //     {
    //         if(arr[index] == arr[j]){
    //             return index;
    //         }
    //     }
    // }

    // Optimized Code
    int mindex = INT_MAX;
    const int N = 1e6+2;
    int idx[N];

    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    for (int i = 0; i < len; i++) // {3,4,6,4,6,1}
    {
        if(idx[arr[i]] != -1){
            mindex = min(mindex,idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
        // mindex = min(mindex,idx[arr[i]]);
    }
    
    if(mindex == INT_MAX){
        cout << "Nothing Found";
    }
    else{
        return mindex;
    }
    return -1;
}


// Indexes in which between the given sum exist by adding first subarray elements
void solve2(){
    int len,s,sum = 0;
    cin >> len >> s;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    // Not Optimized for time complexity
    // for (int i = 0; i < len; i++)
    // {
    //     sum = 0;
    //     for (int j = i; j < len; j++)
    //     {
    //         sum += arr[j];
    //         if(sum == s){
    //             cout << i << " " << j;
    //             return;
    //             // break;
    //         }
    //     }   
    // }
    
    // Optimized for Time Complexity but limitation only work for sorted array
    // int i = 0;
    // while (i<len)
    // {
    //     sum += arr[i];
    //     if(sum == s){
    //     cout << 0 << " " << i;
    //     return;
    //     }
    //     if(sum > s){
    //         break;
    //     }
    //     i++;
    // }

    // for (int j = 0; j < len; j++)
    // {
    //     sum -= arr[j];
    //     if(sum == s){
    //         cout << j+1 << " " << i;
    //         return ;
    //     }
    // }
    

    // Optimized for Time Complexity also work for unsorted array
    int j = 0;
    while (j<len && sum + arr[j] <= s)
    {   
        sum += arr[j];
        j++;
    }
    
    if(sum == s){
        cout << 0 << " " << j;
        return;
    }

    int i = 0;
    while (j<len)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }

        if(sum == s){
        cout << i << " " << j;
        return;
        }
        j++;
    }
    return ;
}

// Find Smallest missing positive number
int solve3(){
    int len,ans,mx = INT_MIN;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        mx = max(mx,arr[i]);
        // cout << "max: " << mx << endl;
    }

    int n = mx+1;

    int check_arr[n];

    for (int j = 0; j < n; j++)
    {
        check_arr[j] = false;
    }

    for (int k = 0; k < len; k++)
    {
        if(arr[k]>0){
        check_arr[arr[k]] = true;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << ": " << check_arr[i] << endl;
    // }
    
    

    for (int l = 1; l < n; l++)
    {
       if(check_arr[l] == false){
         ans = l;
         break;
       }
    }    

    cout << ans << endl;
    return 1;
}


int main(){
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": ";
        solve2();
        // solve3();
        cout << endl;
    }
    return 0;
}