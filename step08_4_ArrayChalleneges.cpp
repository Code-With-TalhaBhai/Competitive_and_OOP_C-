#include <iostream>
#include <math.h>
using namespace std;
void MaxTillI(int arr[],int n);
void SumOfAllSubarrays(int arr[],int n);


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

    // MaxTillI(arr,n);
    SumOfAllSubarrays(arr,n);


    return 0;
}


void MaxTillI(int arr[],int n){
    int current,prev,m = 0;

    for (int i = 0; i < n; i++)
    {
        m = 0;
       while (m<=i)
       {
        //1st method
        if(arr[m] > arr[i]){
            arr[i] = arr[m];
        }
            m++;
       } 


    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    
    cout << endl;

}


void SumOfAllSubarrays(int arr[],int n){
        int m,sum,all;
        m = sum = all = 0;
        // 1st method
        for (int i = 0; i < n; i++)
        {
            m = i;
            sum = 0;
            while (m<n)
            {
                sum += arr[m];
                m++;
                
            }
            cout << sum << endl;
            all += sum;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     m = 0;
        //     while (m>=i)
        //     {
        //         sum += arr[m];
        //         m--;
        //     }
        // }
        
    // return sum;
    cout << endl << endl;
    cout << "Sum of All Subarrays are: " << all << endl;

}