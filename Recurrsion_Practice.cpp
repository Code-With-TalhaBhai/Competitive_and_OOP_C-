#include <iostream>
using namespace std;
#include <cmath>


void func5(int n){
    cout << n << endl;
}

void func4(int n){
    cout << n << endl;
    func5(5);
}

void func3(int n){
    cout << n << endl;
    func4(4);
}

void func2(int n){
    cout << n << endl;
    func3(3);
}

void func1(int n){
    cout << n << endl;
    func2(2);
}


void recurrsion(){
    func1(1);
}


void recurrsion1(int n){
    if(n == 0){
        return;
    }

    cout << n << endl;
    recurrsion1(n-1);
}


void recurrsion2(int n){
    if(n == 0){
        return ;
    }

    recurrsion2(n-1);
    cout << n << endl;
}


int factorial(int n){
    if(n == 1){
        return n;
    }

    return n * factorial(n-1);
}


int SumOfN(int n){
    if(n == 1){
        return n;
    }

    return n + (n-1);
}

int SumOfDigits(int n){
   if(n == 0){
    return 0;
   }

    // return (n%10 + SumOfDigits(n/10));
    return (SumOfDigits(n/10) + n%10);
}


int ProductOfDigits(int n){
    if(n%10 == n){
        return n;
    }

    return (n%10 * ProductOfDigits(n/10));
}

void ReverseNumber(int n){
    cout << n % 10;
    if(n%10 == n){
        return;
    }

    ReverseNumber(n/10);
}

int sum = 0; // External var used in this recurrsion method
void ReverseNumber2(int n){ //4567
    if(n == 0){
        return ;
    }

    sum = sum * 10 +  n%10;

    ReverseNumber2(n/10);
}


int revrecurr(int n,int base){
    if(n%10 == n){
        return n;
    }

    return (n%10 * pow(10,base) + revrecurr(n/10,--base));
}

int ReverseNumber3(int n){

    int base = log10(n)+1; // Return the number of digits

    return revrecurr(n,--base);
}


int countRev(int n,int count){
    if(n/10 == 0){
        return count;
    }

    if(n%10 == 0){
        return countRev(n/10,++count);
    }
    return countRev(n/10,count);

}

int CountZeros(int n){
    return countRev(n,0);
}


int cSteps(int n,int count){
    if(n == 0){
        return count;
    }

    if(n%2 == 0){
        n /= 2;
    }

    else if(n%2 == 1){
        n--;
    }

    return cSteps(n,++count);
}

int CountSteps(int n){
    return cSteps(n,0);
}


int main(){

    int a = 2;
    // recurrsion();

    // n to 1
    recurrsion1(5);

    cout << endl;

    // 1 to n
    recurrsion2(5);

    cout << endl;

    // factorial of a number
    cout << factorial(5)<< endl;

    // sum of n
    cout << SumOfN(5) << endl;

    // sum of digits
    cout << SumOfDigits(5344423) << endl;

    // product of digits
    cout << ProductOfDigits(23423) << endl;

    // Reverse a number
    // Way 1
    cout << "way1" << endl;
    ReverseNumber(2345);
    // Way 2
    cout << endl << "way2" << endl;
    ReverseNumber2(2345);
    cout << sum << endl;
    // Way 3
    cout << "way3" << endl;
    cout << ReverseNumber3(2345) << endl;

    cout << CountZeros(30707400) << endl;

    cout << CountSteps(14) << endl;

    return 0;
}