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
class Pair{
    public:
    Node* n;
    int vtlevel;
    Pair(Node* n1,int x){
        n = n1;
        vtlevel = x;
    }
};
bool Search(Node* root,int k){
    while(root != nullptr){
        if(root->val == k){ 
        return true;
    } else if(root->val > k){
        root = root->left;
    } else {
        root = root->right;
}
}
return false;
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
bool ans = Search(root,k);
cout<<ans<<endl;
return 0; 
}