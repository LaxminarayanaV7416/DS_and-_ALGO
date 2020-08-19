#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* head;

void append_front(int input_data){
    Node* new_node = new Node();
    new_node->data = input_data;
    if(head !=   NULL){
        new_node->next = head;
    }
    head = new_node;
}

void append_end(int input_data){
    Node* new_node = new Node();
    new_node->data = input_data;
    new_node->next = NULL;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void deleteNode(int position){
    // deleting the node;
    Node* temp = head;
    if(position==1){
        head = temp->next;
        delete temp;
    } else {
        for(int i=0;i<position-2;i++){
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
}

void insertAtPosition(int input_data,int position){
    Node* new_node = new Node();
    new_node->data = input_data;
    new_node->next = NULL;
    Node* temp = head;
    if(position==1){
        new_node->next = temp;
        head = new_node;
    } else{
        for(int i=0; i<position-2; i++){
            temp = temp->next;
        }
        new_node-> next = temp->next;
        temp->next = new_node;
    }
}

void reverseLinkedListIteratorMethod(){
    Node *current,*next_position,*previous;
    previous = NULL;
    current = head;
    while(current != NULL){
        next_position = current->next;
        current->next = previous;
        previous = current;
        current = next_position;
    }
    head = previous;
}

void printLinkedList(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printLinkedListRecursion(Node* temp){
    if(temp == NULL){
        return;
    }
    cout << temp->data << " ";
    printLinkedListRecursion(temp->next);
}

void printLinkedListRecursionReverse(Node* temp){
    if(temp == NULL){
        return;
    }
    printLinkedListRecursionReverse(temp->next);
    cout << temp->data << " ";
}

void recursiveReverse(Node* temp){
    if (temp->next == NULL){
        head = temp;
        return;
    }
    recursiveReverse(temp->next);
    Node* temp2 = temp->next;
    temp2->next = temp;
    temp->next = NULL;
}

int main(){
    head = NULL;
    int n,x;
    cout << "Enter how many numbers you want to insert in linked list " << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter the number to insert at beginning of Linked List " << endl;
        cin >> x;
        append_front(x);
        printLinkedListRecursion(head);
        cout << endl;
    }
    cout << "Enter the number to insert in end Linked List " << endl;
    cin >> x;
    append_end(x);
    printLinkedListRecursion(head);
    cout << endl;
    cout << "insert at first position " << endl;
    cin >> x;
    insertAtPosition(x,1);
    printLinkedListRecursion(head);
    cout << endl;
    cout << "insert at any position " << endl;
    cin >> x;
    int pos;
    cout << "please the position to insert " << endl;
    cin >> pos;
    insertAtPosition(x,pos);
    printLinkedListRecursion(head);
    cout << endl;

    // deleteNode(3);
    printLinkedListRecursion(head);
    cout << endl;
    //printLinkedListRecursionReverse(head);
    recursiveReverse(head);
    printLinkedListRecursion(head);
    cout << endl;
}
