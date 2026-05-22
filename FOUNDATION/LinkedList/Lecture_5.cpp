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
void inseratindex(Node* &head,int k,int v){
if(k == 0){
    Node* n1 = new Node(v);
    n1->next = head;
    head = n1;
    return;
}
Node* n1 = new Node(v);
Node* temp = head;
for(int i = 0; i<k-1; i++){
    temp = temp->next;
}
Node* tempp1 = temp->next;
temp->next = n1;
n1->next = tempp1;
}
void printlinkedlist(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
int k;
cin>>k;
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
head->next->next->next = new Node(40);
head->next->next->next->next = new Node(50);
inseratindex(head,k,70);
printlinkedlist(head);
return 0;
}