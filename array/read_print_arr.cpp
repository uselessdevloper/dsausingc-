#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }
}

void display(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    input(arr);
    display(arr);

    return 0;
}