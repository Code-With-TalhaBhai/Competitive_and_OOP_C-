#include<iostream>
#include<stack>
using namespace std;


void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}

void check(bool output){
    if(output == true){
        cout << "Redundant Brackets" << endl;
    }
    else{
        cout << "Not Redundant" << endl;
    }
}

bool redundant_brackets(string str){
    stack<char> S;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            S.push(ch);
        }

        if(ch==')'){
            if(S.top() == '+' || S.top()=='-' || S.top()=='*' || S.top()=='/'){
                 while(S.top()!='('){
                   S.pop();
               }
               S.pop();
            }
            else{
                return true;
            }
        }
    }


    return false;
}


int main(){

    string str1 = "(a+c*b)+(c))";
    string str2 = "(a+b)";
    string str3 = "((a+b))";

    check(redundant_brackets(str1));
    check(redundant_brackets(str2));
    check(redundant_brackets(str3));

    return 0;
}