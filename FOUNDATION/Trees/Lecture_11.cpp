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
void LevelorderI(Node* root){
queue<Node* > q;
q.push(root);
while(q.size() > 0){
Node* rem = q.front();
q.pop();
cout<<rem->data<<endl;
if(rem->left != NULL){
    q.push(rem->left);
} 
if(rem->right != NULL){
    q.push(rem->right);
}
}
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
LevelorderI(root);
return 0;
}
