#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "How much element you want to add in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tmp,counter = 1;
    // int iteration = 0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
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