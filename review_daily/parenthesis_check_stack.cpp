#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

list<char> open_list;
list<char> close_list;
stack<char> our_stack;

bool parenthesisChecker(string s){
    for(int i=0;i<s.length();i++){
        if(find(open_list.begin(),open_list.end(),s[i])!=open_list.end()){
                our_stack.push(s[i]);
            }
        else if(find(close_list.begin(),close_list.end(),s[i])!=close_list.end()){
                if(our_stack.empty()){
                    return false;
                } else{
                    if(s[i]==')' && our_stack.top()=='('){
                        our_stack.pop();
                    } else if(s[i]=='}' && our_stack.top()=='{'){
                        our_stack.pop();
                    } else if(s[i]==']' && our_stack.top()=='['){
                        our_stack.pop();
                    } else{ our_stack.push(s[i]);}
                }
            }
        }
    return our_stack.empty()?true:false;
}

int main(){
    open_list.push_back('{');
    open_list.push_back('(');
    open_list.push_back('[');
    close_list.push_back('}');
    close_list.push_back(')');
    close_list.push_back(']');

    if(parenthesisChecker("[{}}{]")){
        cout << "Balanced String!!!!";
    } else { cout << "Nope am Sorry your string is not Balanced" << endl; }
}
