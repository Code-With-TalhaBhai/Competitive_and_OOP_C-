#include<iostream>
using namespace std;

int divide(int num,int denum){
    int ans = 0;
    try {
        if(denum==0){
            throw 0;
        }
        ans = num/denum;
    }
    catch(int throw_err){
        cout << "Denuminator cannot be divided by: " << throw_err << endl;
    }
    
        return ans;
}



int main(){

    cout << "Before exception handling" << endl;

    int numerator = 643;
    int denuminator = 0;

    cout << divide(numerator,denuminator) << endl;
    denuminator = 54;
    cout << divide(numerator,denuminator) << endl;


    return 0;
}