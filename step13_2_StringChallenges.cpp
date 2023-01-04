#include <iostream>
#include <string>
#include<climits>
#include<algorithm>
using namespace std;


int main(){

    int i = 0;
    string lower = "sjfklsjfkdsl";

    // Lower to Upper case
    while (i<lower.length())
    {
        if(lower[i]>='a' && lower[i] <= 'z'){
        lower[i] -= 32;
        cout << lower[i];
        i++;
        }
        else{
            cout << endl << "We only print alphabets";
        }
    }

    cout << endl;
    i = 0;

    // UpperCase to lowercase()
    while (i<lower.length())
    {
        // if(lower[i]>='A' && lower[i]<='Z'){ // both correct
        if(lower[i]>=65 && lower[i]<=92){
            lower[i] += 32;
            cout << lower[i];
        }

        i++;
    }
    cout << endl;

    
    // Built-in function to go into upper case or lower case (Note: Include header file(algorithm))
    transform(lower.begin(),lower.end(),lower.begin(),::toupper); // transform(First index,Last index,Index which you want to start capitalizing,Upper case or lower case)
    cout << lower << endl;
    
    transform(lower.begin(),lower.end(),lower.begin(),::tolower);
    cout << lower << endl;
    cout << endl << endl;


    // Form the biggest number from the number string
    string number = "5341";
    int mx;
    int z = 0;

    for (int g = 0; g < number.length(); g++)
        {
        if(number[z]>='0' || number[z]<='9'){
            mx = INT_MIN;
            for (int i = g; i < number.length(); i++)
            {
                if(number[i]>mx){
                    mx = number[i];
                    number[i] = number[g];
                }
            }
            number[g] = mx;
            }
    }  
        cout << number << endl;

    string number1 = "6823";
    // Short Method
    sort(number1.begin(),number1.end(),greater<int>());
    cout << number1 << endl;
    cout << endl << endl;

    // Problem 3: Print the maximum occurring character in string
    string occur = "fjdksafjkdslaweirfjfffefjjjjjjjjjjjjjjjakfldajfdsljjjjjjjjjjjj";
    int maxi = INT_MIN;
    int n = 26;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    
    for (int j = 0; j < occur.length(); j++)
    {
        // arr[occur[j]-97]++;
        arr[occur[j]-'a']++; // same as above, above(ascii value uses);
    }


    char repchar;
    for (int k = 0; k < n; k++)
    {
        if(arr[k]>maxi){
            maxi = arr[k];
            // repchar = 97+k;
            repchar = 'a'+k;
        }
    }    
    cout << "Max Repeating Character is: '" << repchar << "', and it repeats '" << maxi << "' times" << endl;
    



    return 0;
}