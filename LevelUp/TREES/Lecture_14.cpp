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
Node* inordersuccessor(Node* root ,int k){
    Node* temp = nullptr;
    while(true){
        if(root->val > k){
temp = root;
root = root->left;
        } else if(root->val <k){
            root = root->right;
        } else {
            break;
        }
    }
    if(root->right == nullptr) return temp;
    Node* rootp1 = root->right;
    while(rootp1->left != nullptr){
        rootp1 = rootp1->left;
    }
    return rootp1;
}
int main() {
int k;
cin>>k;
Node* root = new Node(4);
root->left = new Node(1);
root->left->left = new Node(0);
root->left->right = new Node(2);
root->left->right->right = new Node(3);
root->right = new Node(6);
root->right->right = new Node(7);
root->right->left = new Node(5);
root->right->right->right = new Node(8);
Node* temp = inordersuccessor(root,k);
cout<<temp->val<<endl;
return 0; 
}