#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse_stack(stack<int>& s,string str){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    str = "";
    while(s.empty()!=true){
        str.push_back(s.top());
        s.pop();
    }
    return str;
}


int main(){
    stack<int> S;
    string str = "Talha";
    cout << "Real String is: " << str << endl;
    cout << "Reverse String is: " << reverse_stack(S,str) << endl;

    str = "rotator";
    cout << "Real String is: " << str << endl;
    cout << "Reverse String is: " << reverse_stack(S,str) << endl;
    return 0;
}