//datatypes
#include<iostream>
using namespace std;
int main(){
    //assigning integer data type
    int x=10;
    //long
    long y=18;
    // for the larger number
    long long z=1000000000;
    //floating point number
    float a=10.5;
    //double data type
    double b=9.5;
    //string and getline
    string name;
    cout<<"Enter your name: ";
    getline(cin,name);
    cout<< "Hey "<<name<<endl;
    //character data type
    char ch;
    cin>>ch;
    cout<<"Char is "<<ch<<endl;


    cout << "The value assigned using integer datatype is :"<< x;

}