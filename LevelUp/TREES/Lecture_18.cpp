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
int LCA(Node* root,int n1,int n2){
while(true){
    if(n1<root->val && n2<root->val){
        root = root->left;
    } else if(n1> root->val && n2> root->val){
        root = root->right;
    } else {
        return root->val;
    }
}
}
int main() {
int n1,n2;
cin>>n1>>n2;
Node* root = new Node(40);
root->left = new Node(10);
root->left->left = new Node(0);
root->left->right = new Node(20);
root->left->right->right = new Node(30);
root->right = new Node(60);
root->right->right = new Node(70);
root->right->left = new Node(50);
root->right->right->right = new Node(80);
root->right->right->left = new Node(65);
int temp = LCA(root,n1,n2);
cout<<temp<<endl;
return 0; 
}