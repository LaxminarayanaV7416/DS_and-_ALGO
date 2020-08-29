#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
stack<Node*> S;

void insert(int input_data){
    Node* temp = new Node();
    temp->data = input_data;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void printLL(){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverse(){
    Node* temp = head;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }
    Node* temp2 = S.top();
    head = temp2;
    while(!S.empty()){
        temp2->next = S.top();
        S.pop();
        temp2 = temp2->next;
    }
    temp2->next = NULL;
}

int main(){
    head = NULL;
    insert(20);
    insert(30);
    insert(40);
    printLL();
    reverse();
    printLL();
}
