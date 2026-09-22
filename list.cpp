#include <iostream>
//list
#include <list>
using namespace std;

void explainList(){
    // a doubly linked list is maintained in list 
    list<int> ls;
    //push_back
    ls.push_back(10);
    ls.emplace_back(4);
    //push_front() ver ver less time complexity when we compare to a vector
    ls.push_front(5);
    //emplace_front() takes an pair i.e. {2,4}
    ls.emplace_front();


}
int main(){
    return 0;
}
