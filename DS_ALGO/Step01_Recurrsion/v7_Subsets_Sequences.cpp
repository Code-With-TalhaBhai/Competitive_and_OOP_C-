#include <iostream>
#include<string>
#include<vector>
using namespace std;



void solve1(string str,string ans){

    if(str.length() == 0){
        // cout << "Return working" << endl;
        cout << ans << endl;
        return ;
    }

    char ch = str[0];
    string ros = str.substr(1);

    // cout << "Before recurrsion ch val---> " << ch << endl;

    solve1(ros,ans);

    // cout << "After upper recurrsion ch value --> " << ch  << endl;

    solve1(ros,ans+ch);

    // cout << "Function ends" << endl << endl;
}


// vector <vector <int>> solve2(vector <int> given_arr,vector <vector <int>> ans_arr,vector <int> output_arr,int idx){

//     if(idx >= given_arr.size()){
//         ans_arr.push_back(output_arr);
//         return ans_arr;
//     }


//     return solve2(given_arr,ans_arr,output_arr,idx+1);
//     int element = given_arr[idx];
//     output_arr.push_back(element);
//     return solve2(given_arr,ans_arr,output_arr,idx+1);

//     // ans_arr.push_back({234,5234,435});
//     // ans_arr.push_back({234,435});
//     // return ans_arr;
//     // return {{23432,432,52,523},{234},{23432,235,23}};
// }


void solve2(vector <int> given_arr,vector <vector <int>> &ans_arr,vector <int> output_arr,int idx){

    if(idx >= given_arr.size()){
        ans_arr.push_back(output_arr);
        return ;
    }


    solve2(given_arr,ans_arr,output_arr,idx+1);
    int element = given_arr[idx];
    output_arr.push_back(element);
    solve2(given_arr,ans_arr,output_arr,idx+1);
}


void solve3(string str,vector <string> &str1_ans,string output,int index){

   if(index >= str.length()){
        if(output.length() > 0){
            str1_ans.push_back(output);
        }
            return ;
   }

    solve3(str,str1_ans,output,index+1);

    char element = str[index];
    output.push_back(element);

    solve3(str,str1_ans,output,index+1);
}




int main(){
    
    string str = "abc";
    // Sub-Sequences of string
    // solve1(str,"");


    // Sub-Sequences of array
    vector <int> basic_arr {1,2,3};
    vector <vector <int>> ans_arr;
    vector <int> output_arr;
    int index = 0;
    // solve2(basic_arr,ans_arr,output_arr,index);

    for(vector <int> i:ans_arr){
        cout << "[";
        for(int j:i){
            cout << j << " ";
        }
        cout << "]";
    }



    // Sub-sequences of string using vector
    string str1 = "abc";
    vector <string> str1_ans;
    string str1_output;
    int index_str = 0;
    solve3(str1,str1_ans,str1_output,index_str);

    for(string str:str1_ans){
        cout << str << endl;
    }



    return 0;
}

// https://recursion.vercel.app/
// Python subsets

// def fn(str,ans):
//   if(len(str) == 0):
//      return ans;
  
//   ch = str[0];
//   ros = str[1:];
  
//   fn(ros,ans);
  
//   fn(ros,ans+ch);  def fn(str,ans):
//   if(len(str) == 0):
//      return ans;
  
//   ch = str[0];
//   ros = str[1:];
  
//   fn(ros,ans);
  
//   fn(ros,ans+ch);  





// Js Subsets
// function fn(str,ans) {
//   if(str.length == 0){
//   console.log(ans);
//   return ;
//   }
  
//   let ch = str[0];
//   let ros = str.substr(1);
  
//   fn(ros,ans);
  
//   fn(ros,ch+ans);
  
// }

// fn('abc','')

