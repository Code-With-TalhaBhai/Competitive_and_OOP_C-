#include <iostream>
using namespace std;


int main(){

    int n,term1=0,term2=1,nextTerm=0;
    cout << "Enter the number of terms: ";
    cin >> n;


    for (int i = 0; i <= n; i++)
    {
        if(i == 0 || i == 1){
            cout << i << "\t";
            continue;
        }

        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;

        cout << nextTerm << "\t";


    }
    


    return 0;
}