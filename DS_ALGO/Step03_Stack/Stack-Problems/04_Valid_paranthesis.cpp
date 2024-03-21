#include<iostream>
#include<stack>
using namespace std;

bool valid_paranthesis(string str){
    stack<int> S;
    for(int i=0; i<str.length(); i++){
        char br_close = str[i];
        if(br_close == ')' || br_close == '}' || br_close == ']'){
            if(!S.empty()){
                char br_open = S.top();
                if( 
                    (br_open=='(' && br_close==')') || 
                    (br_open=='{' && br_close=='}') ||
                    (br_open=='[' && br_close==']')
                ){
                    S.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            char br_to_push = str[i];
            S.push(br_to_push);
        }
    }
    return true;
}

void check(bool output){
    if(output == true){
        cout << "It is balanced. Valid Paranthesis" << endl;
    }
    else{
        cout << "Not balanced. Invalid Paranthesis" << endl;
    }
}

int main(){

    string str1 = "[()]{}{[()()]()}";
    string str2 = "[[{}[]]]";
    string str3 = "[{{}(]]";
    string str4 = "[](){}";

    check(valid_paranthesis(str1));
    check(valid_paranthesis(str2));
    check(valid_paranthesis(str3));
    check(valid_paranthesis(str4));

    return 0;
}