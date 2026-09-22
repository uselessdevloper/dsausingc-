#include <iostream>
#include <queue>
using namespace std;

void explainDeque(){
    deque<int> dq;
    dq.push_back(10);
    dq.emplace_back(100);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.back();
    dq.front();


}
int main(){
    return 0;
}