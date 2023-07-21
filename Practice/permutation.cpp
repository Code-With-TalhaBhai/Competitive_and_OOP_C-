#include<iostream>
#include<vector> 
using namespace  std;
 
void permutation(string str,int index,string output,vector <string> &ans){

    if(index >= str.length()){
        ans.push_back(str);
        return ;
    }
    
    for(int i=index; i<str.length(); i++){
        swap(str[index],str[i]);
        permutation(str,index+1,output,ans);
        swap(str[index],str[i]);
    }


}
 


int main(){

    string str,output;
    vector <string> ans;
    cin >> str;
    int index = 0;

    permutation(str,index,output,ans);

    for(string i:ans){
        cout << i << endl;
    }

    return 0;
}