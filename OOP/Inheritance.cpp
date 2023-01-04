#include <iostream>
using namespace std;
/*
There are 5 types of Inheritance

1. Single Inheritance
2. Multiple Inheritance
3. Multi-level Inheritance
4. Hybrid Inheritance (Muliple Inh + Multi-level Inh)
5. Heirarchical Inheritance

*/

class Human {
    int maxLifeSpan;
    protected:
        char gender;
    public: 
        string name;
        int age;
        float height;
        float weight;
        string education;


    // void getAttributes(){
    //     cout << maxLifeSpan << endl;
    //     cout << gender << endl;
    //     cout << name << endl;
    //     cout << age << endl;
    //     cout << height << endl;
    //     cout << weight << endl;
    //     cout << education << endl;
    // }
};

class Male : private Human {
    int gender = 'M';
};

class Female: private Human {
    public: 
    Female(char c_gender,string c_name,int c_age,int c_height,int c_weight,string c_education){
        gender = c_gender;
        name = c_name;
        age = c_age;
        height = c_height;
        weight = c_weight;
        education = c_education;
    }


    void getAttributes(){
        cout << name << endl;
        cout << age << endl;
        cout << height << endl;
        cout << weight << endl;
        cout << education << endl;
        cout << gender << endl;
    }

};


// private public derived class relationship
    class Base{
        int x;
        public:
        int y;
        protected: 
        int z;
    };


    class derived1: public Base{
        // x is inaccessible of Base Class
        // y is public
        // z is protected
    };

    class derived2: protected Base{
        // x is inaccessible
        // y is protected
        // z is protected
    };

    class derived3: private Base{
        // x is inaccessible
        // y is private
        // z is private
    }


int main(){


    // Without-Constructor
    // Male M;
    // Female F;

    // F.name = "Khali";
    // F.age = 53;
    // F.height = 23.3;
    // F.weight = 123.5;
    // F.education = "Masters in Computer";
    // F.getAttributes();
    // F.getGender();
    // cout << endl;



    // With-Constructor
    Female F1('F',"Sumaila",43,23,123,"Phd Doct.");
    F1.getAttributes();


    return 0;
}
