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
//here if we use &s then the changes made in the 
//function will be reflected in the main function as well 
// this is called pass by reference just use & before the variable name in the function parameter
void doSomething(string &s){
    s[0]='R';
    cout<<s<<endl;
}
int main(){
    string name;
    cin>>name;
    printName(name);
    string s="Hello";
    doSomething(s);
    cout<<s<<endl;
    return 0;

}
