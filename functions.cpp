#include <iostream>
using namespace std;
//funcn are set of codes together collectively
//used to modularise code
//used to increase readability
//used to use same code multiple times
/*
void()- doesn't return anything
return- returns a value
parameterized- takes parameters using which we can perform operations
non parameterized- no parameters are taken
*/
void printName(string name){
    cout<<"Hello "<<name<<endl;
}
int main(){
    string name;
    cin>>name;
    printName(name);
    return 0;
}