// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void recurrsion(int start,int end){
    if(start>=end){
        cout << "(" << start << "," << end << ")" << endl;
        return ;
    }
    
    int mid = (start + end)/2;
    recurrsion(start,mid);
    
    cout << "(" << start << "," << end << ")" << endl;
}


int main() {
    // Write C++ code here
    recurrsion(0,10);

    return 0;
}