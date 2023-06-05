#include <iostream>
using namespace std;

int power(int n){
    if(n == 0){
        return 1;
    }

    return 2 * power(n-1);
}



// power of 2 ^ n
int solve1(){
    int n;
    // cout  << "Enter the power of: ";
    cin >> n;
    return power(n);
}



int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << solve1() << endl;
    }


    return 0;
}