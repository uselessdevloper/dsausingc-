#include <iostream>
#include <vector>
#include <algorithm>
//A vector can grow or shrink: vector<int> arr;
/*
arr.push_back(10);
arr.push_back(20);
arr.push_back(30);
arr
 ↓
[10, 20, 30]
*/

/*
| Function      | Purpose                       |
| ------------- | ----------------------------- |
| `push_back()` | Add element at the end        |
| `pop_back()`  | Remove last element           |
| `size()`      | Get number of elements        |
| `front()`     | Get first element             |
| `back()`      | Get last element              |
| `clear()`     | Remove all elements           |
| `empty()`     | Check whether vector is empty |
| `insert()`    | Insert element at a position  |
| `erase()`     | Remove element                |
*/
using namespace std;
int main(){
    int arr[5];
    double arr2[10];
    cin>>arr[0];
    cin>>arr[1];
    cin>>arr[2];
    cin>>arr[3];
    cin>>arr[4];
    arr[3]=1999;
    cout<<arr[3]<<endl;
    return 0;

}