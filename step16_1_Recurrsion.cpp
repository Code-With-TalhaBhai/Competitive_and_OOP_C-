#include<iostream>
using namespace std;

// Recurrsions
int recurrsion1(int n){

    if(n == 1){
        return 1;
    }

    int final = n + recurrsion1(n-1);
    return final;   
}

int recurrsion2(int n,int power){
    if(power == 1){
        return n*1;
    }

    int final = n * recurrsion2(n,power-1);
    return final;
}

int recurrsion3(int n){
    if(n == 1){
        return 1;
    }

    int final = n*recurrsion3(n-1);
    return final;
}

void recurrsion4(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int fabonacci = recurrsion4(n-1) + recurrsion4(n-2);

    return fabonacci;
}







// Problems
// Find Sum till n through recurrsion
int solve1(){

    int n;
    cin >> n;
    return recurrsion1(n);        
}


// Write a function that calculate n raised to power of p;
int solve2(){

    int n,p;
    cin >> n >> p;
    return recurrsion2(n,p);        
}

// Print the factorial of given number
int solve3(){
    int n;
    cin >> n;
    return recurrsion3(n);      
}


// Print the nth fabonacci series
int solve4(){
    int n;
    cin >> n;
    cout << 0 << endl << 1 << endl;
    return recurrsion4(n); 
}



int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        // cout << "Case #" << i << ": " << solve2() << endl;
        // cout << "Case #" << i << ": " << solve3() << endl;
        cout << "Case #" << i << ": " <<  solve4() << endl;
    }

    return 0;
}