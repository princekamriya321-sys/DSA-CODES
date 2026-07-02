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
bool isBST(Node* root,int minval,int maxval){
 if(root == nullptr) return true;
if(root->val < minval || root->val > maxval){
    return false;
}
bool l = isBST(root->left,minval,root->val -1);
bool r = isBST(root->right,root->val + 1,maxval);
if(l&&r) return true; else return false;
}
int main() {
Node* root = new Node(15);
root->left = new Node(10);
root->left->left = new Node(5);
root->right = new Node(21);
root->left->left->left = new Node(1);
root->left->left->right = new Node(8);
root->right->right = new Node(27);
root->right->right->right = new Node(34);
root->right->right->left = new Node(24);
bool ans = isBST(root,INT_MIN,INT_MAX);
cout<<ans<<endl;
return 0; 
}