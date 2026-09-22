#include <iostream>
#include <stack>
using namespace std;

void explainStack(){
    //Lifo- Last In First Out
    stack<int> st;
    st.push(1);//1
    st.push(2);//2,1
    st.push(3);//3,2,1
    st.push(3);//3,3,2,1
    st.emplace(5);//5,3,3,2,1

    cout<<st.top();//5
    st.pop();//3,2,2,2
    cout<<st.top();//3
    st.pop();
    cout<<st.size();
    cout<<st.empty();
    stack<int> st1,st2;
    st1.swap(st2);
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}
int main(){
    explainStack();
    return 0;
}
