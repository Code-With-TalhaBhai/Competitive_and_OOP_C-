#include <iostream>
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

    int ongoing , k;

    for (int i = 1; i < n; i++)
    {
        ongoing = arr[i];
        k = i - 1;
        while (arr[k]>ongoing && k>=1){
            arr[k+1] = arr[k];
            k--;
        }
        arr[k] = ongoing;
    }
    
    

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