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
void insert(Node* root,int k){
    Node* n = new Node(k);
    while(true){
        if(root->val > k){
            if(root->left == nullptr) {
                root->left = n;
                return;
            } else {
                root = root->left;
            }
        } else {
            if(root->right == nullptr){
                root->right = n;
                return;
            } else {
                root = root->right;
            }
        }
    }
}
int main() {
int k;
cin>>k;
Node* root = new Node(15);
root->left = new Node(10);
root->left->left = new Node(5);
root->right = new Node(21);
root->left->left->left = new Node(1);
root->left->left->right = new Node(8);
root->right->right = new Node(27);
root->right->right->right = new Node(34);
root->right->right->left = new Node(24);
insert(root,k);
return 0; 
}