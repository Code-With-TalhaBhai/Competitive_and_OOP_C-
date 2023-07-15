#include <iostream>
#include <vector>
using namespace std;

// abc   bac    cab         // i = 0;
//  abc    bac    cab       // i = 1;
//   acb    bca     cba     // i = 2;.



void permutations(string str,int index,vector <string> &permutation_arr){

    if(index >= str.length()){
        permutation_arr.push_back(str);
        return;
    }


    for (int i = index; i < str.length(); i++)
    {
        swap(str[i],str[index]);
        permutations(str,index+1,permutation_arr);
        swap(str[i],str[index]);
    }

}




int main(){

    int index = 0;
    vector <string> permutation_arr;
    string str;
    cin >> str;

    permutations(str,index,permutation_arr);

    for(string i:permutation_arr){
        cout << i << endl;
    }

    return 0;
}


