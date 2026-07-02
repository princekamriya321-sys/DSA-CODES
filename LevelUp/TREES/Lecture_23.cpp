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
static int a = 0;
int Diameter(Node* root){
if(root == nullptr) return -1;
int lht = Diameter(root->left);
int rht = Diameter(root->right);
a = max(a,lht+rht+2);
return max(lht,rht) +1;
}
int main() {
Node* root = new Node(6);
root->right = new Node(8);
root->right->right = new Node(29);
root->right->right->left = new Node(20);
root->right->right->left->right = new Node(23);
root->right->right->left->right->right = new Node(25);
root->right->right->left->left = new Node(15);
root->right->right->left->left->left = new Node(9);
root->right->right->left->left->left->right = new Node(10);
root->right->right->left->left->left->right->right = new Node(13);
root->right->right->left->left->right = new Node(17);
root->right->right->left->left->right->right = new Node(19);
// root->right->left = new Node(5);
root->right->right->right = new Node(32);
root->right->right->right->right = new Node(35);
root->right->right->right->right->right = new Node(39);
root->right->right->right->right->left = new Node(33);
root->right->right->right->left = new Node(30);
// root->right->right->left = new Node(73);
int ans = Diameter(root);
cout<<a<<endl;
return 0; 
}