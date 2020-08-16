#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    // Vector is a container
    vector<int> myFirstVector;
    myFirstVector.push_back(4);
    myFirstVector.push_back(1);
    myFirstVector.push_back(8);

    // we need to convert the vector to iterator so that we can apply algorithms on that
    vector<int>::iterator itrBegin = myFirstVector.begin();
    vector<int>::iterator itrEnd = myFirstVector.end();

    // lets write a forloop for iterator we defined above;
    for(vector<int>::iterator itr=itrBegin; itr!=itrEnd; ++itr){
        cout << *itr << " ";
    }

    cout << endl;

    for(auto vecValue : myFirstVector){
        cout << vecValue << " ";
    }

    cout << endl;

    // lets apply some algorthim like sort on iterator we defined above;
    sort(itrBegin,itrEnd);
    for(auto vectorValue: myFirstVector){
        cout << vectorValue << " ";
    }
    return 0;
}
