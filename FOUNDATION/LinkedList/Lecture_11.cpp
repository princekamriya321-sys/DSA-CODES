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
Node* Floydscycle(Node*head){
Node* s = head;
Node* f = head;
//Detect FLoyd's Cycle if it exist.
while(f!= NULL && f->next != NULL){
    s = s->next;
    f = f->next->next;
if(s == f) break;
}
s = head;
if(f == NULL || f->next == NULL){return NULL;}
while(s != f){
    s = s->next;
    f = f->next->next;
}
if(f == NULL){
    return NULL;
}
s = head;
while(s!= f){
    s = s->next;
    f = f->next;
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
// Creating cycle
    head->next->next->next->next = head->next;
Node *ans = Floydscycle(head);
cout<<ans->data<<endl;
return 0;
}