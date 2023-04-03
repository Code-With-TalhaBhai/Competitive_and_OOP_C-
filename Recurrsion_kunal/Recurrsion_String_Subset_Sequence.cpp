#include <iostream>
using namespace std;
#include <string>

string solve1(string str,int index,int len){

     if(str[index] == 'a'){
        str.erase(index,1);
        // cout << str.length() << endl;
    }


    if(str.length() == 0 || len == (index+1)){
        return str;
    }

    return solve1(str,++index,len);
}


string solve2(string str){

    int find = str.find("really");
    if(find == -1){
        return str;
    }else{
        str.erase(find,6);
        return solve2(str);
    }
}

void solve3(string str,string rem){

    if(str.length() == 0){
        cout << rem << endl;
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);

    solve3(ros,rem);
    solve3(ros,rem+ch);
}

/*
    " "
    a
    b
    c
    ab
    ac
    bc 
    abc
*/




string skipcharacter(){
    string str = "abacdeadfa";
    return solve1(str,0,str.length());
}

string skipString(){
    string str = "This is really a really good enough really thing of really";
    return solve2(str);
}

string subSequences(){
    string str = "abc";
    solve3(str,"");
    return str;
}



int main(){

    int t = 1;
    for (int i = 1; i <= 1; i++)
    {
        // cout << "Case " << i <<": " << skipcharacter() << endl;
        // cout << "Case " << i <<": " << skipString() << endl;
        cout << "Case " << i <<": " << subSequences() << endl;
    }

    return 0;
}