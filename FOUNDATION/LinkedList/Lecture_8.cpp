#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
int data;
Node *next;
Node(int val){
    data = val;
    next = NULL;
}
};
void Reverselinkedlist(Node* &head){
Node* curr = head;
Node* prev = NULL;
while(curr != NULL){
    Node* currp1 = curr->next;
    curr->next = prev;
    prev = curr;
    curr = currp1;
}
head = prev;
}
void printlinkedlist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
head->next->next->next = new Node(40);
head->next->next->next->next = new Node(50);
Reverselinkedlist(head);
printlinkedlist(head);
return 0;
}