#include <iostream>
#include<vector>
using namespace std;

void keypad_problem(string digits,int index,string output,vector<string> &ans_arr,string mapping[]){

    if(digits.length() == 0){
        return ;
        
    }

    if(index >= digits.length()){
        ans_arr.push_back(output);
        return;
    } 


    int digIdx = digits[index] - '0';
    string map_str = mapping[digIdx];

    for (int i = 0; i < map_str.length(); i++)
    {
        // 1st way ---> Not Changing Value Just Sending
        // keypad_problem(digits,index+1,output+map_str[i],ans_arr,mapping);

        // 2nd way ---> Changing OUTPUT value and then send it
        output.push_back(map_str[i]);
        keypad_problem(digits,index+1,output,ans_arr,mapping);
        output.pop_back(); // backtracking
    }

}



int main(){

    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index = 0;
    string output = "";
    string digits;
    cin >> digits;
    vector <string> ans_arr;
    keypad_problem(digits,index,output,ans_arr,mapping);
    for(string i:ans_arr){
        cout << i << endl;
    }


    // string str;
    // for (int i = 0; i < digits.length(); i++)
    // {
    //     char element = digits[i];
    //     int idx = element - '0';
    //     str += mapping[idx];
    // }
    
    // cout << str;
    // keypad_problem(str,index,output,ans_arr,mapping);



    // for(string i:ans_arr){
    //     cout << i << endl;
    // }


    return 0;
}