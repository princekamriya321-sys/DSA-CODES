#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
public:
char val;
Node* left;
Node* right;
Node(char v){
    val = v;
    left = nullptr;
    right = nullptr;
}
};
Node* LCA(Node* root,char n1,char n2){
    if(root == nullptr) return nullptr;
    if(root->val == n1 || root->val == n2) return root;
    
    Node* l = LCA(root->left,n1,n2);
    Node* r = LCA(root->right,n1,n2);
    if(l!= nullptr && r != nullptr){
        return root;
    }
    if(l != nullptr && r == nullptr) return l;
    if(r != nullptr && l == nullptr) return r;

    return nullptr;
}
int main() {
char n1,n2;
cin>>n1>>n2;
Node* root = new Node('C');
root->left = new Node('D');
root->left->left = new Node('E');
root->left->left->right = new Node('N');
root->left->left->left = new Node('J');
root->left->right = new Node('F');
root->left->right->left = new Node('M');
root->right = new Node('G');
root->right->right = new Node('I');
Node* temp = LCA(root,n1,n2);
cout<<temp->val<<endl;
return 0; 
}