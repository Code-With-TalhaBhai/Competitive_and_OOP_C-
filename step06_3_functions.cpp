#include<iostream>
#include<cmath>
#include<string>  



using namespace std;
int sumNatural(int n);
void  pythagorian_triplet();
int octal_to_decimal();
int getDigit(int n);
int conversion_to_decimal(int base);
int hexadecimal_to_decimal();
int hexadecimal_to_decimal1();
string decimal_to_binary();


int main(){
    int n;
    // cout << "Please enter any number: ";
    // cin >> n;

    cout << "We are printing sum of first n natural numebers" << endl;
    // cout << "Sum of Natural Numbers are: " << sumNatural(n) << endl;

    cout << "We are checking whether it is Pythagorian Triplet" << endl;
    // pythagorian_triplet();

    cout << "We are converting octal to decimal" << endl;
    // octal_to_decimal();

    // int base;
    // cout << "We are doing conversions to decimal by telling base" << endl;
    // cout << "Enter the base for conversion 2 for binary and 8 for octal: ";
    // cin >> base;
    // if(base == 2 || base == 8){
    //     conversion_to_decimal(base);
    // }


    // cout << hexadecimal_to_decimal()  << endl;

    // cout << "HexaDecimal to Decimal Method # 2";
    // cout << hexadecimal_to_decimal1()  << endl;

    cout << "Binary to Decimal is: " << decimal_to_binary() << endl;

}

int sumNatural(int n){
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
}


void pythagorian_triplet(){
    int a,b,c; // --> Input
    int x,y,z; // --> Comparing

    cout << "Please, Enter any three numbers: ";
    cin >> a >> b >> c;

    x = max(a,max(b,c));

    if(x == a){
        y = b;
        z = c;
    }
    else if(x == b){
        y = a;
        z = c;
    }
    else {
        y = a;
        z = b;
    }

    if(x*x == y*y + z*z){
        cout <<  "It's a Pythgorial triplet" << endl;
    }
    else {
        cout << x*x << " "<< y*y + z*z;
        cout << "Its not a triplet" << endl;
    }

}

int getDigit(int n){

    int digits = 1;
    int iter = 1;

    while((int)(n/pow(10,digits)) > 0){
        digits++;
    }
    return digits;
}


int octal_to_decimal(){
    cout << endl << endl;
    int n;
    cout << "Please enter any number: ";
    cin >> n;
    int total = 0;
    int total_digits = getDigit(n);
    int remainder = n%10;
    int next_term = n;

    for (int i = 0; i < total_digits; i++)
    {   
        next_term = (next_term - remainder)/10;
        if(remainder < 8){
        total += remainder * ((int)pow(8,i));
        // cout << "next_term " << next_term << " remainder " << remainder << " power " << (int)pow(8,i) << " total " << total << endl;
        remainder = next_term%10;
        }else{
            char choice;
            cout << "Please enter the terms between 0 and 7 for octal numbers" << endl;
            cout << "Would you like to again run this function.Enter 'Y' or 'N': ";
            cin >> choice;
            if(choice == 'Y' || 'y'){
                octal_to_decimal();
            }
                return 0;
        }
    }

    cout << "Octal to Decimal is: " << total << endl;
    return total;
}


int conversion_to_decimal(int base){
    int func_base = base;
    cout << endl << endl;
    int n;
    cout << "Please enter any number: ";
    cin >> n;
    int total = 0;
    int total_digits = getDigit(n);
    int remainder = n%10;
    int next_term = n;


    for (int i = 0; i < total_digits; i++)
    {   
        next_term = (next_term - remainder)/10;
        if(remainder < base){
        total += remainder * ((int)pow(base,i));
        // cout << "next_term " << next_term << " remainder " << remainder << " power " << (int)pow(8,i) << " total " << total << endl;
        remainder = next_term%10;
        }
        else{
            char choice;
            cout << "Please enter the terms between 0 and " << base-1 << endl;
            cout << "Would you like to again run this function again. Enter 'Y' or 'N': ";
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
                conversion_to_decimal(func_base);
            }
            return 0;
        }
    }

    if(base == 2){
    cout << "Binary to Decimal is: " << total << endl;
    }
    if(base == 8){
    cout << "Octal to Decimal is: " << total << endl;
    }
    return total;
}


int hexadecimal_to_decimal(){
    string input,final;
    int ans = 0;
    unsigned long int total = 0;
    cout << "Enter any hexadecimal number: ";
    cin >> input;
    int length = input.length();

    for (int i = 0; i < input.length(); i++)
    {
        char switch_value = input[i];
        switch (switch_value)
        {
        case 'A':
        case 'a':
            ans = 10;
            break;

        case 'B':
        case 'b':
            ans = 11;
            break;

        case 'C':
        case 'c':
            ans = 12;
            break;

        case 'D':
        case 'd':
            ans = 13;
            break;
        
        case 'E':
        case 'e':
            ans = 14;
             break;

        case 'F':
        case 'f':
            ans = 15;
             break;

        default:
            ans = (int)(switch_value - '0'); // Converting to int without getting into ASCII value
            break;
}
    // cout << "Conversion" << ans << endl;
    length--;

    total += ans * pow(16,length);

    cout << ans << "* 16 ^" << length <<" = " << total << endl;

    }
    return total;
}


int hexadecimal_to_decimal1(){
    string input;
    long int x = 1;
    long unsigned int ans;
    ans = 0;
    unsigned long int total = 0;
    cout << "Enter any hexadecimal number: ";
    cin >> input;
    int length = input.length();

    int i = length-1;
    while(i >= 0){  
        if(input[i]>='0' && input[i]<='9'){
            ans += x*(input[i]-'0'); 
        }
        else if(input[i] >= 'A' && input[i] <= 'F'){
            ans += x*(input[i]-'A'+10); 
        }
        // else{
        //     cout << "Please Enter hexadecimal number: ";
        //     return 0;
        // }
        x *= 16;
        // cout << "Input: " << input[i] << " * " << i << " " << x << " = " << ans << endl;
        i--;
    }

    return ans;
}


string decimal_to_binary(){
    // not complete
    int input,rem,term;
    string bin;
    // bin = "fjskl";
    // bin[2] = 'g';
    cout << "string: " << bin;
    cout << "Enter any decimal number: ";
    cin >> input;

    rem = input%2;
    term = input/2;
    // for (int i = 0; i < (int)(input/pow(10,i)); i++)
    int i = 1;
    while((int)(input/pow(10,i)) > 0)
    {
     cout << "rem" << rem << endl;
     bin[i] = rem == 0 ? char(rem) - '48': char(rem) - '49'; 
     cout << "bin" << bin[i] << endl;
     term /= 2;
     rem = term%2;  
     i++;
    }

    cout << "binary" << bin;
    return bin;

}