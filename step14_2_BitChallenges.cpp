#include <iostream>
using namespace std;


// Write a program to check if a given number is power of 2
void solve1(){
    int n;
    cin >> n;
    // ((n & (n-1)) == 0) ? cout << "Yes,it is" : cout << "No,it isn't";
    (n && ((n & (n-1)) == 0)) ? cout << "Yes,it is" : cout << "No,it isn't"; // Also for zero
}

// Write a program to count the number of ones in binary representation of a number
int solve2(){
    int n,count = 0;
    cin >> n;
    while(n){
        n = n & n - 1;
        count++;
    }
    return count;
}


// Write a program to generate all possible values of a subset   S = {a,b,c}
void solve3(){

    int n = 5;
    char arr[n] = {'a','b','c','d','e'};

    // For SubArray
    // for (int i = 0; i < n; i++)
    // {
    //      for (int j = i; j < n; j++)
    //      {
    //          for (int k = i; k <= j; k++)
    //          {
    //              cout << arr[k] << " ";
    //          }
    //          cout << endl;
    //      }        
    // }



    // For Subset
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i & (1<<j)){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    
    
    
}


int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        // solve1();
        // cout << "Case #" << i << ": " << solve2() << endl;
        // cout << endl << solve2() << endl;
        solve3();
    }

    return 0;
}