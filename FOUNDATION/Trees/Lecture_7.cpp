#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node{
 // Preorder traversal
public:
int data;
Node* left;
Node* right;
Node(int val){
data = val;
left = NULL;
right = NULL;
}
};
void Traversal(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Traversal(root->left);
    Traversal(root->right);
}
int main(){
Node *root = new Node(14);
root->left = new Node(18);
root->left->left = new Node(7);
root->right = new Node(19);
root->left->right = new Node(3);
root->left->right->left = new Node(10);
root->right->right = new Node(8);
root->right->right->left = new Node(4);
root->right->right->right = new Node(15);
Traversal(root);
return 0;
}