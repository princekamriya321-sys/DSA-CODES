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
vector<int> ans;
void LevelorderII(Node* root){
queue<Node* > q;
q.push(root);
while(q.size() > 0){
int n = q.size();
for(int i = 1; i<=n; i++){
Node* rem = q.front();
q.pop();
ans.push_back(rem->data);
if(rem->right != NULL){
    q.push(rem->right);
}
if(rem->left != NULL){
    q.push(rem->left);
} 
}
}
}
int main(){
Node *root = new Node(14);
root->left = new Node(18);
root->right = new Node(19);
root->left->right = new Node(3);
root->left->right->left = new Node(10);
root->right->right = new Node(140);
root->right->left = new Node(4);
LevelorderII(root);
reverse(ans.begin(), ans.end());
int n = ans.size();
for(int i = 0; i<n; i++){
    cout<<ans[i]<<" ";
}
return 0;
}
