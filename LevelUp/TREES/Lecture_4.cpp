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
void bottomview(Node* root){
    queue<Pair*> q;
 map<int,Node*> mp;
    q.push(new Pair(root,0));
while(q.size()>0){
    Pair* rem = q.front();
    q.pop();
Node* remn = rem->n;
int remvt = rem->vtlevel;
    mp[remvt] = remn;

if(remn->left != nullptr) q.push(new Pair(remn->left,remvt-1));
if(remn->right != nullptr) q.push(new Pair(remn->right,remvt+1)); 
}
for(auto& v : mp){
    cout<< v.second->val<<" ";
}
}
int main() {
Node* root = new Node(10);
root->left = new Node(20);
root->left->left = new Node(49);
root->right = new Node(30);
root->left->right = new Node(50);
root->left->right->left = new Node(80);
root->left->right->left->left = new Node(100);
root->right->left = new Node(60);
root->right->right = new Node(70);
root->right->left->right = new Node(90);
root->right->left->right->right = new Node(110);

bottomview(root);
return 0; 
}