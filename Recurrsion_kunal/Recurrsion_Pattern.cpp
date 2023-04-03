#include<iostream>
using namespace std;

void solve1(int start,int iter,int total){
    cout << "*" ;
    
    if(start == total && iter == total){
        return;
    }


    if(start == iter){
        cout << endl;
        solve1(++start,1,total);
    }else{
        solve1(start,++iter,total);
    }
}


void solve2(int start,int iter){

    cout << "*";

    if(start == 1 && iter == 1){
        return;
    }


    if (iter == 1)
    {
        cout << endl;
        solve2(--start,start);
    }else{
        solve2(start,--iter);
    }
}


void solve3(int arr[],int index,int iter,int len){
    if(index == len){
        return ;
    }
    
    if(arr[index]>arr[iter]){
        int temp = arr[index];
        arr[index] = arr[iter];
        arr[iter] = temp;
    }

    if(iter == len){
        ++index;
        solve3(arr,index,index+1,len);
    }
    else{
    solve3(arr,index,++iter,len);
    }
}


void solve4(int arr[],int iter,int index,int len){
    if(index+1 == len){
        return ;
    }


    if(arr[iter]>arr[iter+1]){
        int temp = arr[iter];
        arr[iter] = arr[iter+1];
        arr[iter+1] = temp;
    }


    if(iter+1 == len){
        solve4(arr,0,++index,len);
    }
    else{
        solve4(arr,++iter,index,len);
    }
    
}







void pattern1(){
    int t;
    cin >> t;
    solve1(1,1,t);
}


void pattern2(){
    int t;
    cin >> t;
    solve2(t,t);
}


void selection_sort(){
    int n = 9;
    int arr[n] = {23,532,632,46,6,4,23,1,64};
    solve3(arr,0,1,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
};

void buble_sort(){
    int n = 10;
    int arr[n] = {23,532,632,3,46,6,4,23,1,64};
    // IN looop
    // for (int i = n; i > 1; i--)
    // {
    //     for (int j = 0; j < i-1; j++)
    //     {
    //         if(arr[j] > arr[j+1]){
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //     }
    // }    

    // 2nd way
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < n-i; j++)
    //     {
    //         if(arr[j] > arr[j+1]){
    //         int temp = arr[j];
    //         arr[j] = arr[j+1];
    //         arr[j+1] = temp;
    //         }
    //     }
    // }
    
    // Recurrsion
    solve4(arr,0,1,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}



int main(){

    int t = 1;
    for (int i = 1; i <= 1; i++)
    {
        cout << "Case " << i <<": " << endl;
        // Triangle Patterns
        pattern1();
        cout << endl;
        pattern2();
        cout << endl;


        // Sorting
        // selection_sort();
        cout << endl;
        // buble_sort();
    }
    

    return 1;
}