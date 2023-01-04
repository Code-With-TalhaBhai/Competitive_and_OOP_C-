#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "How much element you want to add in array: ";
    cin >> n;

    int arr[n],tmp;
    cout << "Enter your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int iteration = 0;
    for (int z = 0; z < n; z++)
    {
        for (int l = 0; l < n-1; l++)  
        {
            if(arr[l] > arr[l+1]){
                tmp = arr[l+1];
                arr[l+1] = arr[l];
                arr[l] = tmp;
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