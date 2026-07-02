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
   static int greaterval = 0;
void helper(Node* root){
    if(root == nullptr) return;
    helper(root->right);
    greaterval += root->val;
    root->val = greaterval;
    helper(root->left);
}
Node* Sumtogreater(Node* root){
    helper(root);
    return root;
}
void printInorder(Node* root){
    if(root == nullptr) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main() {
Node* root = new Node(4);
root->left = new Node(1);
root->left->left = new Node(0);
root->left->right = new Node(2);
root->left->right->right = new Node(3);
root->right = new Node(6);
root->right->right = new Node(7);
root->right->left = new Node(5);
root->right->right->right = new Node(8);
Node* temp = Sumtogreater(root);
cout << "After Recovery: ";
printInorder(temp);
cout << endl;
return 0; 
}