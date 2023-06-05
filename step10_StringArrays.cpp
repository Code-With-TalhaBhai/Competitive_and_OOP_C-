#include <iostream>
// #include<string>
using namespace std;

int main(){

    char arr[100] = "Programmer";
    
    int i = 0;
    while(arr[i] != '\0'){
        cout << arr[i];
        i++;
    }
    cout << endl;


    // Check PALINDROME(Reverse string is also same)
    bool bool1 = true;
    char drome[100];
    cin >> drome;

    int n = 0;
    while (drome[n] != '\0')
    {
        n++;
    }


    int j = 0; 
    while (j<n)
    {
        if(drome[j] != drome[n-1-j]){
            bool1 = false;
            break;
        }
        j++;
    }
    
    if(bool1){
        cout << "It's Palindromic" << endl;
    }


    // Program to check every word and prints most longest word
    int z = 100;
    char sentence[z];
    cin.getline(sentence,z);
    cin.ignore();

    int k = 0;
    int length = 0;
    int maxLen = 0;
    int start = 0;

    while (1) // true always looping
    {
        if(sentence[k] == ' ' || sentence[k] == '\0'){
            if(length>maxLen){
                maxLen = length;
                start = k - maxLen;
            }
            length = 0;
        }
        length++;

        if(sentence[k] == 'a'){
            break;
        }
        k++;
    }
    
    cout << maxLen << endl;

    int a = start;
    // Printing Longer word
    while (a <= maxLen)
    {
        cout << sentence[a];
        a++;
    }

    return 0;
}