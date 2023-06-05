#include <iostream>
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


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


    // For loop
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i -1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
    


    // With while loop
    // int i = 1;
    // while (i<n){
    //     int temp = arr[i];
    //     int j = i - 1;
    //     while (j>=0 && arr[j] > temp)
    //     {
    //             arr[j+1] = arr[j];
    //         j--;
    //     }
    //     arr[j+1] = temp;
    //     i++;
    // }
    

    
    print(arr,n);

    // int current;
    // for (int i = 0; i < n; i++)
    // {
    //     int current = arr[i];
    //     int j = i-1;

    //     while (arr[j]>current && j>=0)
    //     {
    //         arr[j+1]=arr[j];
    //         j--;
    //         cout << "{";
    //         for (int k = 0; k < n; k++)
    //         { 
    //             if(k == n-1){
    //             cout << arr[k];
    //             }
    //             else{
    //             cout << arr[k] << ", " ;
    //             }
    //         }
    //         cout << "}" << endl;
    //     }
    //     arr[j+1]=current;
    //     cout << "{";
    //         for (int k = 0; k < n; k++)
    //         {
    //             if(k == n-1){
    //             cout << arr[k];
    //             }
    //             else{
    //             cout << arr[k] << ", " ;
    //             }
    //         }
    //     cout << "}" << endl;

    //     cout << endl << endl;
    // }    


    return 0;
}