#include<iostream>
#include<vector>
using namespace std;


void keypad_combs(string str,int index,string mapping[],string output,vector <string> &ans){

    if(index>=str.length()){
        ans.push_back(output);
        return;
    }

    int num = str[index] - '0';
    string map_str = mapping[num];

    for(int i=0; i<map_str.length(); i++){
        output.push_back(map_str[i]);
        keypad_combs(str,index+1,mapping,output,ans);
        output.pop_back();
    }

}



int main(){

    vector <string> ans;
    string output;

    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string str;
    cin >> str;

    if(str.length > 0){
        keypad_combs(str,index,mapping,output,ans);
    }
    else{
        cout << " " << endl;
    }


    for(string i:ans){
        cout << i << endl;
    }

    return 0;
}