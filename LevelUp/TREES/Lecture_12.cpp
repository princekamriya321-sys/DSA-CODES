#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* left;
Node* right;
Node(int v){
    val = v;
    left = nullptr;
    right = nullptr;
}
};
Node* f = nullptr;
Node* s = nullptr;
Node* previous = nullptr;
void inorder(Node* curr){
    if(curr == nullptr) return ;
    inorder(curr->left);
    if(previous != nullptr && curr->val < previous->val && f == nullptr){
        f = previous;
        s = curr;
    } else if(previous != nullptr && curr->val < previous->val && f != nullptr){
        s = curr;
    }
    previous = curr;
    inorder(curr->right);
}
void printInorder(Node* root){
    if(root == nullptr) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main() {
Node* root = new Node(15);
root->left = new Node(10);
root->left->left = new Node(21);
root->right = new Node(5);
root->left->left->left = new Node(1);
root->left->left->right = new Node(8);
root->right->right = new Node(27);
root->right->right->right = new Node(34);
root->right->right->left = new Node(24);

cout << "Before Recovery: ";
printInorder(root);
cout << endl;

inorder(root);

if(f && s){
    swap(f->val, s->val);
}

cout << "After Recovery: ";
printInorder(root);
cout << endl;
return 0; 
}