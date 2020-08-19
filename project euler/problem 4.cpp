#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPalindrome(string str){
    bool output = true;
    int len = str.length();
    int lenMinusOne = len-1;
    for(int i=0;i<=(len/2);i++){
        int start = i;
        int last = lenMinusOne-i;
        if(str[start]!=str[last]){
            output = false;
            break;
        }
    }
    return output;
}

int main(){
    list<int> l;
    for(int i=100;i<1000;i++){
        for(int j=100;j<=i;j++){
            string str = to_string(i*j);
            if(isPalindrome(str)){
                int element = stoi(str);
                l.push_back(element);
            }
        }
    }
    int maxel=0;
    for(auto x:l){
        if(x>maxel){
            maxel = x;
        }
    }
    cout << maxel << " ";
}
