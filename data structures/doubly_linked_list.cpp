#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

void insertAtEnd(int input_data){
    Node* temp = new Node();
    temp->data = input_data;
    temp->next = NULL;
    temp->prev = NULL;
    Node* temp2 = head;
    if(temp2==NULL){
        head = temp;
    } else {
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}

void insertAtBegining(int input_data){
    Node* temp = new Node();
    temp->data = input_data;
    temp->next = NULL;
    temp->prev = NULL;
    Node* temp2 = head;
    temp2->prev = temp;
    temp->next = temp2;
    head = temp;
}
 /*
void insertAtPlace(int input_data, int position){
    Node* temp = new Node();
    temp->data = input_data;
    temp->next = NULL;
    temp->prev = NULL;
    Node* temp2 = head;
    if(position==1){
        temp2->prev = temp;
        temp->next = temp2;
        head = temp;
    } else {
        for(int i=0;i<position-2;i++){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        temp->prev = temp2;
        temp2->next->prev = temp;
    }
}
*/

void insertAtPlace(int input_data, int position){
    if(position==1){
        insertAtBegining(input_data);
        return;
    }
    Node* temp = new Node();
    temp->data = input_data;
    temp->next = NULL;
    temp->prev = NULL;
    Node* temp2 = head;
    for(int i=0;i<position-2;i++){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    temp->prev = temp2;
    temp2->next->prev = temp;

}

void printLinkedList(){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
    head = NULL;
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtBegining(10);
    insertAtBegining(20);
    insertAtPlace(30,2);
    insertAtPlace(40,3);
    insertAtPlace(0,1);
    printLinkedList();

}
