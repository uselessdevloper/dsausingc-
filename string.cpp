// This file is part of the C++ standard library implementation.
//#include <string>
//#include <bits/stdc++.h>
//manipulating strings
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s = "Utkarsh";
    int len=s.size();
    s[len-1]='g';
    cout<<s<<endl;
    return 0;
}
