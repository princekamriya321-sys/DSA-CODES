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
void Leftview(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        int n = q.size();
        for(int i = 1; i<=n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 1) cout<<temp->val<<" ";
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
        }
        cout<<endl;
    }

}
int main() {
Node* root = new Node(14);
root->left = new Node(18);
root->right = new Node(19);
root->left->right = new Node(3);
root->left->right->left = new Node(10);
root->right->left = new Node(4);
root->right->right = new Node(140);

Leftview(root);
return 0; 
}