#include<iostream>
#include<math.h>
using namespace std;

int main(){

    // Write a program to check whether prime number or not.
    int prime;
    cout << "Enter any prime number: ";
    cin >> prime;
    bool check = true;

    for (int i = 2; i <= sqrt(prime); i++) // We use sqrt() function to check prime number, As the number above of sqrt is a multiple of number above sqrt() number.
    {
        if(prime%i == 0){
            check = false;
            cout << prime << " isn't a prime number" << endl;
            break;
        }  
    }
    
    if(check == 1){
        cout << prime << " is a  PRIME NUMBER" << endl;
    }


    // Reverse a number
    int tmp = 0;
    int rev,lastDigit;
    cout << "Enter a number you want to reverse: ";
    cin >> rev;


    while (rev > 0)
    {
        lastDigit = rev % 10;
        tmp = (tmp*10) + lastDigit; 
        rev /= 10; 
    }
    
    cout << tmp << " is the result" << endl;
    

    // Check if a number is armstrong or not
    int total, num, pwr,digit,ch_num,subch_num;
    total = pwr = 0;
    cout << "Enter any number: ";
    cin >> num;

    subch_num = ch_num = num;

    while(ch_num > 0){
        ch_num /= 10;
        pwr++;
    }

    while (num > 0)
    {   
        digit = num%10;
        total+= pow(digit,pwr);
        num /= 10;
    }
    
    if(subch_num == total){
        cout << subch_num << " is an armstrong number" << endl;
    }
    else{
         cout << subch_num << " is not an armstrong number" << endl;
    }

}