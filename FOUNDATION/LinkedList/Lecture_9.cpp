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
Node *Mid(Node*head){
Node* s = head;
Node* f = head;
while(f->next != NULL && f->next->next != NULL){
    s = s->next;
    f = f->next->next;
}
return s;
}
int main(){
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);
head->next->next->next = new Node(40);
head->next->next->next->next = new Node(50);
head->next->next->next->next->next = new Node(60);
Node* ans = Mid(head);
cout<<ans->data<<endl;
return 0;
}