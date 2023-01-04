#include <iostream>
#include <climits>
using namespace std;


int main(){

    int arr[5] = {234,432,4323,53,64};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }


    // Takes input element of array and find maximum between them;
    int n;
    cout << "How much element you want to print in an array: ";
    cin >> n;

    int input_arr[n];

    cout << "Enter elements of array: ";

    for (int j = 0; j < n; j++)
    {
        cin >> input_arr[j];
    }
    

    int MaxNum = INT_MIN; // Min Number available in C++ --> Must inclue header file(climits)
    int MinNum = INT_MAX; // MAX Number available in C++

    for (int k = 0; k < n; k++)
    { 
        // 1st Method
        // MaxNum = MaxNum > input_arr[k] ? MaxNum : input_arr[k];   
        // MinNum = MinNum < input_arr[k] ? MinNum : input_arr[k];

        // 2nd Method
        MaxNum = max(MaxNum,input_arr[k]);
        MinNum = min(MinNum,input_arr[k]);
    }
    
    cout << "MaxNum is: " << MaxNum << endl;
    cout << "MinNum is: " << MinNum << endl;
    
     

    return 0;
}