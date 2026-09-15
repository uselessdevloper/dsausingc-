#include <iostream>
using namespace std;
// printing 5 times the name entered by the user 
//using for loop 
int main(){
    string name;
    cout<<"Enter your name";
    cin>>name;
    for(int i=0;i<name.size();i++){
        cout<<name<<"hii"<<endl;
    }
    return 0;

}