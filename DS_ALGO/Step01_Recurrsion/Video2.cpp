#include <iostream>
#include <string>
using namespace std;

void iter(string str[],int num){

    
    if(num == 0){
        return ;
    }

    iter(str,num/10);
    
    cout << str[num%10] << " ";
}


int main(){

    int n;
    string str[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    cin >> n;
    iter(str,n);


    return 0;
}