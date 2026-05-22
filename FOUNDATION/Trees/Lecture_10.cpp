#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{

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
int Sum(Node *root){
    if(root == NULL){
        return 0;
    }
    int x = Sum(root->left);
    int y = Sum(root->right);
return x + y + root->data;
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
int ans = Sum(root);
cout<<ans<<endl;
return 0;
}