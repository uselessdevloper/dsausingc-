#include <iostream>
#include <utility>
using namespace std;
// 4 parts
/*
1. Algorithms
2. Containers
3. Functions
4. Iterators
*/
void explainPair(){
    pair<int,int> p={1,2};
	cout << p.first <<" "<< p.second << endl;
}
void NestedPair(){
    pair<int,int> p1={1,2};
    pair<int,pair<int,int>> p2={1,{2,3}};
    cout << p2.first <<" "<< p2.second.first <<" "<< p2.second.second << endl;
}
void ArrayOfPairs(){
    pair<int,int> arr[]={{1,2},{2,3},{4,5}};
    for(int i=0;i<3;i++){
        cout << arr[i].first <<" "<< arr[i].second<<" ";
    }
    cout<<endl;
}

int main() {
    explainPair();
    NestedPair();
    ArrayOfPairs();
	return 0;
}
