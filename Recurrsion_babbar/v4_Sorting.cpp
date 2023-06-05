#include <iostream>
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void reverse_str(string& str,int i,int j){
    if(i >= j){
        return ;
    }

    swap(str[i],str[j]);
    reverse_str(str,++i,--j);
}


bool palindrome(string str,int i,int j){
    
    if(i >= j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }
    return palindrome(str,++i,--j);
}


int raised_to_power(int num,int power){
    
    // cout << "num --> " << num << " power -->" << power << endl;


    if(power == 0){
        return 1;
    }

    if(power == 1){
        // cout << "power 1 running" << endl;
        return num;
    }

    int ans = raised_to_power(num,power/2);
    // cout << " ans " << ans << endl;

    if(power % 2 == 0){
        // cout << "if even running" << endl;
        // return raised_to_power(num,power/2) * raised_to_power(num,power/2);
        return ans * ans;
    }

    else{ // power % 2 == 1
        // cout << "else odd running" << endl;
        // --power; // optional as power/2  minimizes automatically
        // return num * raised_to_power(num,power/2) * raised_to_power(num,power/2);
        return num * ans * ans;
    }

}

int raised_to_power_conventional(int num,int power,int ans){

    cout << "num --> " << num << " power -->" << power << endl;
    if(power == 0){
        return 0;
    }

    if(power == 1){
        cout << "power 1 running" << endl;
        return ans;
    }

    return raised_to_power_conventional(num,--power,ans*num);
}

// void bubble_sort(int arr[],int pointer,int iter,int n){
void bubble_sort(int arr[],int n){

    if(n == 0 || n == 1){
        return ;
    }
    // With two parameters
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    bubble_sort(arr,--n);


    // With four parameters
    // int temp = 0; 
    // if(pointer == n-1){
    //     return ;
    // }

    // if(arr[iter] > arr[iter + 1]){
    //     temp = arr[iter];
    //     arr[iter] = arr[iter+1];
    //     arr[iter+1] = temp;
    // }

    // if(iter < n-pointer){
    //     iter++;
    // }
    // else{
    //     pointer++;
    //     iter = 0;
    // }
    
    // bubble_sort(arr,pointer,iter,n);


// //    With loops
//    int i,j;
//    i = j = 0;
//     // Smaller To Greater
//     while (i<n)
//     {
//         j = 0;
//         while(j<n-i){
//             if(arr[j] > arr[j+1]){
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//             j++;
//         }
//       i++;
//     }

    //    i = j = temp = 0;
    // Greater to Smaller
    // while (i<n)
    // {
    //     j = i;
    //     // print(arr,n); // dont care program
    //     while(j<(n-1))
    //     {
    //         if(arr[j+1] > arr[j]){
    //             temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //         j++;
    //     }
    //     i++;
    // }
}


void insertion_sort(int arr[],int n){ // With Two parameters
// void insertion_sort(int arr[],int n,int i = 1){ // With three parameters

    //With Two parameters
    if(n == 0){
        return ;
    }

    insertion_sort(arr,--n);

    int temp = arr[n];
    int j = n - 1;

    while (arr[j] > temp &&  j>=0)
    {
        arr[j+1] = arr[j];
        j--;
    }
    
    arr[j+1 ] = temp;


    // With three parameters

    // if(i == n){
    //     return;
    // }
    // int temp = arr[i];
    // int j = i - 1;
    // while (arr[j] > temp && j>=0)
    // {
    //     arr[j+1] = arr[j];
    //     // cout << "loop " << i << endl;
    //     j--;
    // }
    // arr[j+1] = temp;
    // insertion_sort(arr,n,++i);


    // With only loop
    // for (int i = 1; i < n; i++)
    // {
    //     int temp = arr[i];
    //     int j = i - 1;
    //     for (; j >= 0; j--)
    //     {
    //         if(arr[j] > temp){
    //             arr[j+1] = arr[j];
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     arr[j+1] = temp;
    // }   

}


void selection_sort(int arr[],int n){

    if(n == 0 || n == 1) {
        return;
    }

    n--;

    // With Recurrsion
    // 1st way
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > arr[n]){
            swap(arr[i],arr[n]);
        }
    }

    //2nd way
    // for (int i = n-1 ; i >= 0; i--)
    // {
    //     if(arr[i] > arr[n]){
    //         swap(arr[i],arr[n]);
    //     }
    // }
    
    
    selection_sort(arr,n);


    // With loop
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if(arr[i] > arr[j]){
    //             swap(arr[i],arr[j]);
    //         }
    //     } 
    //         // print(arr,n);
    // }   

}




void solve1(){
    string str;
    cin >> str;
    reverse_str(str,0,str.length()-1);
    cout << str << endl;
}

void solve2(){
    string str;
    cin >> str;
    if(palindrome(str,0,str.length()-1)){ // word or reverse same(mom);
        cout << "It is palindrome" << endl;
    }
    else{
        cout << "It is not a palidrome word" << endl;
    }
}

int solve3(){
    int num,pow;
    cin >> num;
    cin >> pow;

    return raised_to_power(num,pow);
    // return raised_to_power_conventional(num,pow,1);
}

void solve4(){
    int n = 7;
    int arr[n] = {432,523,53,56,72,1,86};
    // bubble_sort(arr,0,0,n); // With four parameters
    bubble_sort(arr,n); // With two parameters and semi-loop

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 

    cout << "bubble sorting" << endl;
}

void solve5(){
    int n = 8;
    int arr[n] = {34,235,2,34,234,23513235,23,67};

    selection_sort(arr,n); // With two parameters and semi-loop

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << "Selection sort running" << endl;
}


void solve6(){
    int n = 7;
    int arr[n] = {432,523,53,56,72,1,86};

    insertion_sort(arr,n); // With two parameters and semi-loop

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } 

    cout << "Insertion sort running" << endl;
}


int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " ;
        // solve1();
        // solve2();
        // cout << solve3() << endl;
        // solve4(); // bubble_sort
        solve5(); // selection_sort
        // solve6(); // insertion_sort
    }
    
    return 0;
}