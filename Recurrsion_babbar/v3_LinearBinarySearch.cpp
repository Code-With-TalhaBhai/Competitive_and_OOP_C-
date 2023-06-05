#include <iostream>
using namespace std;


int sorted(int arr[],int n,int start){
    if(start + 1 == n){
        return 1;
    }
    else if(arr[start+1] >= arr[start]){
        return sorted(arr,n,++start);
    }
    else{
        return -1;
    }
}

int sum(int arr[],int len){

    if(len == 0){
        return arr[0];
    }

    return arr[len]  + sum(arr,--len);
}


int linearSearch(int arr[],int start,int len,int search){

    if(arr[start] == search){
        return start;
    }
    else if(start + 1 == len){
        return -1;
    }
    return linearSearch(arr,++start,len,search);
};


int binarySearch(int arr[],int start,int end,int search){

    int mid;
    // with loop
    // while (start <= end)
    // {
    //     mid = (start + end)/2;
    //     if(arr[mid] == search){
    //         return mid;
    //     }

    //     else if(search < arr[mid]){
    //         end = mid - 1;
    //     }
    //     else{
    //         start = mid + 1;
    //     }
    // }


    // With Recurrsion
    mid = (start + end)/2; 
    if(start > end){
        return -1;
    }
    
    else if(arr[mid] == search){
        return mid;
    }
    else if(arr[mid] > search){
        // end = mid - 1;
        // return binarySearch(arr,start,end, search);
        return binarySearch(arr,start,mid - 1, search);
    }
    else{
        // start = mid + 1;
        // return binarySearch(arr,start,end,search);
        return binarySearch(arr,mid + 1,end,search);
    }
}



void solve1(){
    int n,s;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >>  arr[i];
    }
    cin >> s;
    cout << sorted(arr,n,0) << endl;
    cout << sum(arr,n-1) << endl;
    cout << linearSearch(arr,0,n,s) << endl;
    cout << endl;
    cout << binarySearch(arr,0,n,s) << endl;
}


int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " ;
        solve1();
        cout << endl;

        // cout << "Case #" << i << ": " << solve2() << endl ;

    }

    return 0;
}