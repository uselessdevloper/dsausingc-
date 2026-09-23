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
    //front() fucntion points to the front of the queue 
    dq.front();


}
void explainQueue(){
    queue<int> q;

}
int main(){
    return 0;
}