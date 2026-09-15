//2d array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int arr[3][5];
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    //print the array
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}