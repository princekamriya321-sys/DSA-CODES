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
//Pass head by refrence to change the
void internalhead(Node* &head, int v){
    Node* n1 = new Node(v);
    n1->next = head;
    head = n1;
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
internalhead(head,50);
printlinkedlist(head);
    return 0;
}