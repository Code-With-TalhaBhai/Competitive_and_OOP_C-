#include<iostream>

using namespace std;

int main(){

    int n;
    cout << "How much element you want to add: ";
    cin >> n;

    int arr[n];
    cout << "Enter your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m,temp;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            }
        }    
    }
    



    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;


    return 0;
}