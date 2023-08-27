#include<iostream>
using namespace std;


int main(){

    struct {
        int id = 432;
        string name = "Talha";
        bool young = true;
    } athele;

    cout << athele.id << endl;
    cout << athele.name << endl;
    cout << athele.young << endl;


    // Named Structs - You can make variable data-type with it
    struct car {
        string color;
        int model;
        bool new_model;
    };


    car c1;

        c1.color = "fjdskl";
        c1.model = 4532;
        c1.new_model = false;

        cout << c1;


    // Unions - union is a type of structure used where the amount of memory is a key-factor
    union uno {
        int total_countries;
        int head_offices;
        string full_form;
    };

    cout << "First value at the allocated memory "<< endl;
    uno.total_countries = 523;
    cout << "Second value store in memory after removing the previous value"<< endl;
    uno.head_offices = 543;
    cout << "Third value store in memory after removing the previous value"<< endl;
    uno.full_form = "United Nations";


    return 0;
}