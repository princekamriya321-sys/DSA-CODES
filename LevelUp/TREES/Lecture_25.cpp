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

void Helper(Node* root,string &s){
    if(root == nullptr){
        s += "# ";
        return;
    }
    s += to_string(root->val) + " ";
    Helper(root->left,s);
    Helper(root->right,s);
}
string Serialize(Node* root){
    string s;
    Helper(root,s);
    return s;
}
int main() {
Node* root = new Node(6);
root->right = new Node(8);
root->right->right = new Node(29);
root->right->right->left = new Node(20);
root->right->right->left->right = new Node(23);
root->right->right->left->right->right = new Node(25);
root->right->right->left->left = new Node(15);
root->right->right->left->left->left = new Node(9);
root->right->right->left->left->left->right = new Node(10);
root->right->right->left->left->left->right->right = new Node(13);
root->right->right->left->left->right = new Node(17);
root->right->right->left->left->right->right = new Node(19);
// root->right->left = new Node(5);
root->right->right->right = new Node(32);
root->right->right->right->right = new Node(35);
root->right->right->right->right->right = new Node(39);
root->right->right->right->right->left = new Node(33);
root->right->right->right->left = new Node(30);
// root->right->right->left = new Node(73);
string s = Serialize(root);
cout<<s<<endl;
return 0; 
}