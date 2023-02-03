#include <iostream>
using namespace std;


// How many numbers are divisible between A and B (e.g How many numbers are divisble from 1 to 1000 by (5 or 7))
int solve1(){
    int n,a,b;
    cin>>n>>a>>b;

    int num = 0;
    
    // Brute-Force Approach
    // for (int i = 0; i < n; i++)
    // {
    //     if(i%a == 0 || i%b == 0){
    //         num++;
    //     }
    // }


    // Optimized Approach
    int c1,c2,common;
    c1 = n/a;
    c2 = n/b;
    common = n/(a*b);

    num = c1+c2-common;



    return num;
}


// Find GCD(Greatest Common Divisor(HCF)) by EUCLIDEAN ALGORITHM
int solve2(){
    int a,b;
    cin >> a >> b;
    int mod;

    while(b!=0){
        mod = a % b;
        a = b;
        b = mod;
    }

    return a;
}



int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": " << solve2() << endl;
    }

    return 0;
}