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
void inseratend(Node* &head,int v){
Node* n1 = new Node(v);
Node* temp = head;
while(temp->next != NULL){
    temp = temp->next;
}
temp->next = n1;
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
inseratend(head,50);
printlinkedlist(head);
return 0;
}