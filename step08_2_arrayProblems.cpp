#include <iostream>
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse_array(int arr[],int n){
    int start,end;
    start = 0;
    end = n - 1;

    // With while loop
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
    // With For loop
    // for (; start <= end; start++)
    // {
    //     swap(arr[start],arr[end]);
    //     end--;
    // } 
}


void merge_sorted_array(int arr1[],int i,int arr2[],int j,int arr3[]){

    int m,n,k;
    m = n = k = 0;

    // 1st way
    while (m<i && n<j)
    {
        if(arr1[m] < arr2[n]){
            arr3[k] = arr1[m];
            m++;
        }
        else{
            arr3[k] = arr2[n];
            n++;
        }
        k++;
    }
    

    while (m<i)
    {
        arr3[k] = arr1[m];
        m++;
        k++;
    }
    
    while (n<j)
    {
        arr3[k] = arr2[n];
        n++;
        k++;
    }


    // 2nd way
    // while (m < i || n < j)
    // {
    //     if(arr1[m] < arr2[n]){
    //         arr3[k] = arr1[m];
    //         m++;
    //     }
    //     else{
    //         arr3[k] = arr2[n];
    //         n++;
    //     }
    //     k++;
    // }
}


void replace_zeroes(int array1[],int s1,int array2[],int s2){
    int i,j,ref;
    ref = i = j = 0;

    int zerostartIndex = 3;

    while (i < s1)
    {
        print(array1,s1);
        // cout << "I: " << i << endl;
        // cout << "J: " << j << endl;
    if(array2[j] < array1[i] && array1[i] != 0){
        ref = i;
        while (ref < zerostartIndex)
        {
            array1[ref+1] = array1[ref];
            ref++;
        }
        zerostartIndex++;
        array1[i] = array2[j];
        j++;
    }
        i++;
    }

}




void transfer_zero(int arr[],int index){

    int j;
    // MOVE TO RIGHT
    j = 0;
    for (int i = 0; i < index; i++)
    {
        if(arr[i] != 0){
            swap(arr[i],arr[j++]);
        }
    }
    
    // MOVE TO LEFT
    j = index - 1;
    for (int i = j; i >= 0; i--)
    {
        if(arr[i] != 0){
            swap(arr[i],arr[j--]);
        }
    } 
    
}




int main(){

    int n = 7;
    int arr[n] = {234,543,2346,42346,4236,2,1};

    // Reverse an array
    reverse_array(arr,n);
    // print(arr,n);

    int i = 8;
    int arr1[i] = {2,23,33,34,37,67,235,23513235};

    int j = 3;
    int arr2[j] = {32,542,890};


    int arr3[i+j] = {};
    merge_sorted_array(arr1,i,arr2,j,arr3);
    // print(arr3,i+j);


    // Replace zeros with elements and sorted
    int array1[6] = {1,2,3,0,0,0};
    int array2[3] = {2,5,7};
    replace_zeroes(array1,6,array2,3);
    print(array1,6);


    // Transfer all zeroes
    int index = 8;
    int zero_arr[index] = {0,23,25,0,0,12,5,0};
    transfer_zero(zero_arr,index);
    // print(zero_arr,index);

    return 0;
}