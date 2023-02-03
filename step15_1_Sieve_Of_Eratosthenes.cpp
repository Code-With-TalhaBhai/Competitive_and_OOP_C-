#include <iostream>
using namespace std;


// Through Sieve_Of_Eratosthenes -----> Print Prime numbers upto given user input
void solve1(){
    int n;
    cin >> n;

    int arr[n] = {0};

    for (int i = 2; i <= n; i++)
    {
        // Marked all the array 0 except no-prime numbers 1;
        if(arr[i] == 0){
            for (int j = i*i; j <= n; j+=i)
            {
                arr[j] = 1;
            }
            
        }
    }

    for (int k = 2; k <= n; k++)
    {
        if(arr[k]==0){
            cout << k << endl;
        }
    }
}

// Prime Factorization using Sieve
void solve2(){
    int n;
    cin >> n;

    int arr[n] = {0};

    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }
    
    for (int i = 2; i <= n; i++)
    {
        if(arr[i] == i){
            for (int j = i*i; j <= n; j+=i)
            {
                if(arr[j] == j){
                    arr[j] = i;
                }
            }  
        }
    }
    
    while (n!=1)
    {
        cout << arr[n] << " ";
        n = n/arr[n];
    }
}


int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": ";
        // solve1();
        solve2();
        // solve3();
    }
    return 0;
}