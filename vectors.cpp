#include <iostream>
using namespace std;

//vectors are dynamic in nature that means whenever we want we can increase or decrease the size of the vector.
// It is a sequence container that encapsulates dynamic size arrays.
void explainVector(){
    vector <int> v;
    //pushback() is used to insert the element at the end of the vector.
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "The size of the vector is: " << v.size() << endl;
    //emplace_back() is used to insert the element at the end of the vector.
    v.emplace_back(4);
    cout << "The size of the vector is: " << v.size() << endl;
    //difference between push_back() and emplace_back() is that push_back() creates a temporary object and then copies or moves it into the vector, while emplace_back() constructs the object in place, which can be more efficient.
    cout << "The elements of the vector are: ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    //vector using pairs
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(100,99);
    vec.emplace_back(99,100);
    cout << endl << "The elements of the vector of pairs are: ";
    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << " ";
    }

    //container of vectors
    //this creates a vector of size 5, with all elements initialized to 100.
    vector<int> vcon(5,100);
    cout << endl << "The elements of the vector of container are: ";
    for(int i=0;i<vcon.size();i++){
        cout << vcon[i] << " ";
    }
    //vector just of size 5, with all elements initialized to 0.
    vector<int> vnew(5);
    //even after initializing the vector of size 5 we can still add more elements to it using push_back() or emplace_back().
    vnew.emplace_back(90);
    cout << endl << "The elements of the vector of size 5 are: ";
    for(int i=0;i<vnew.size();i++){
        cout << vnew[i] << " ";
    }
    //copying one vector to another vector
    vector<int> vcopy(v.begin(),v.end());
    cout << endl << "The elements of the copied vector are: ";
    for(int i=0;i<vcopy.size();i++){
        cout << vcopy[i] << " ";
    }
    //accessing a particular element of the vector using at() function
    cout << endl << "The element at index 2 is: " << v.at(2) << endl;
    //removing the last element of the vector using pop_back() function
    v.pop_back();
    cout << "The elements of the vector after pop_back() are: ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    //using iterators to traverse the vector
    cout << endl << "The elements of the vector using iterators are: ";
    vector <int> a={10,20,30,40,50};
    //iterator - points to the memory location of the first element of the vector
    vector<int>::iterator it=a.begin();
    it++;
    // * is used to access the element from the memory 
    cout<<*(it)<<" ";
    //v.end() - points to the memory location right after the last element of the vector
    vector<int>::iterator it1=a.end();
    it1--;
    //rend()-points to the memory location right before the first element of the vector
    vector<int>::reverse_iterator it2=a.rend();
    //rbegin()-points to the memory location of the last element of the vector
    vector<int>::reverse_iterator it3=a.rbegin();

    //printing the elements of the vector using iterators
    for(vector<int>::iterator it=a.begin();it!=a.end();it++){
        cout<<*(it)<<" ";

    }
    cout<<endl;

    //short way to print the elements of the vector
    //auto keyword is used to automatically deduce the type of the variable from its initializer.
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;
    //using for each loop to traverse the vector
    for(auto it:a){
        cout<<it<<" ";
    }
    //delete all the elements of the vector using erase() function
    a.erase(a.begin()+1);
    cout<<endl<<"The elements of the vector after erase() are: ";
    for(auto it:a){
        cout<<it<<" "; 
    }
    //deleting all the elements of the vector using clear() function
    a.clear();
    cout<<endl<<"The size of the vector after clear() is: "<<a.size()<<endl;

    //erase function can also be used to delete a range of elements from the vector. For example, to delete the first two elements of the vector, we can use the following code:
    vector<int> b={1,2,3,4,5};
    b.erase(b.begin(),b.begin()+2);
    cout<<"The elements of the vector after erasing the first two elements are: ";
    for(auto it:b){
        cout<<it<<" ";// 3 4 5
    }
    cout<<endl;
    //insert function can be used to insert an element at a specific position in the vector. For example, to insert the element 10 at the second position of the vector, we can use the following code:
    vector<int> c={1,2,3,4,5};
    c.insert(c.begin()+1,10);
    cout<<"The elements of the vector after inserting 10 at the second position are: ";
    for(auto it:c){
        cout<<it<<" ";// 1 10 2 3 4 5
    }
    // inserting 2 elements at the second position of the vector using insert() function
    c.insert(c.begin()+1,2,20);
    //insert a vector at the second position of the vector using insert() function
    vector<int> d={30,40,50};
    c.insert(c.begin()+1,d.begin(),d.end());
    cout<<endl<<"The elements of the vector after inserting 2 elements at the second position are: ";
    for(auto it:c){
        cout<<it<<" ";// 1 30 40 50 10 20
    }
    //v.size() function returns the number of elements in the vector. It is a constant time operation.
    //v.pop_back() function removes the last element of the vector. It is a constant time operation.
    //v.swap() function swaps the contents of two vectors. It is a constant time operation.
    //v.clear(); removes all the elements of the vector. It is a linear time operation.
    //v.empty() function returns true if the vector is empty, otherwise it returns false. It is a constant time operation.
    

}

int main(){
    explainVector();
    return 0;

}