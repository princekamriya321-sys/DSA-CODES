#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* left;
Node* right;
Node* next;
Node(int v){
    val = v;
    left = nullptr;
    right = nullptr;
    next = nullptr;
}
};
void nextpointer(Node* root){
    while(root->left != nullptr){
Node* temp = root;
while(temp!= nullptr){
    temp->left->next = temp->right;
    if(temp->next != nullptr){
        temp->right->next = temp->next->left;
    }
    temp = temp->next;
}
root = root->left;
    }
}
int main() {
Node* root = new Node(4);
root->left = new Node(1);
root->left->left = new Node(0);
root->left->right = new Node(2);
root->left->right->right = new Node(3);
root->left->right->left = new Node(9);
root->right = new Node(6);
root->right->right = new Node(7);
root->right->left = new Node(5);
root->right->right->right = new Node(8);
root->right->right->left = new Node(73);

return 0; 
}