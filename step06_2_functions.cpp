#include<iostream>
using namespace std;

bool checkPrime(int n){
    if(n == 1 || n == 3 || n == 5 || n == 7){
        return true;
    }
    else if(n%2 == 0 || n%3 == 0 || n%5 == 0 || n%7 == 0){
        return false;
    }
    else{
        return true;
    }
}

void fabonacci_func(int n){
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    for (int i = 0; i < n; i++)
    {
        cout << t1 << " ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    
}

int factorial(int n){
    int total = 1;
    for (int i = n; i >= 1; i--)
    {   
        total *= i;
    }
    return total;
}

long int combination_func(int n,int r){
    long int C;

    C = factorial(n)/(factorial(r)*factorial(n-r));
    // cout << factorial(r) << "inside";
    // cout << factorial(n-r) << "inside";

    return C;
}

void pascal_triangle(int n){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << combination_func(i,j) << " ";
        }
        cout << endl;
    }
    

}



int main(){
    int n;


    // Write a function to check whether a number is prime or not.
    cout << "We are printing Prime Number Function: " << endl;
    cout << "Please enter any number: ";
    cin >> n;
    if(checkPrime(n)){
        cout << n << " is a prime number" << endl;
    }
    else{
        cout << n << " isn't a prime number" << endl;
    }


    // Write a function that prints fabonacci sequence
    cout << "We are printing fabonacci sequence " << endl;
    fabonacci_func(n);


    // Write a function that prints factorial of n
    cout << "We are printing factorial " << endl;
    cout << factorial(n) << endl;

    // Write a function that calculates combination factoraial using formula
    //  nCr = n!/r!(n-r)!
    cout << "We are printing Combination factorial " << endl;
    cout << "Combination: "<< combination_func(n,5) << endl;

    // Write a function that prints Pascal Triangle
    cout << "We are printing Pascal Triangle " << endl;
    pascal_triangle(n);

    return 0;
}