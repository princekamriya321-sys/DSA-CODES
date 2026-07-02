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
Node* Helper(vector<string> &tokens,int &idx){
if(tokens[idx] == "#"){
    idx++;
    return nullptr;
}
Node* root = new Node(stoi(tokens[idx]));
idx++;
root->left = Helper(tokens,idx);
root->right = Helper(tokens,idx);
return root;
}
Node* Deserialize(string &s){
    stringstream ss(s);
    string token;
  vector<string> tokens;
  while(ss >> token){
    tokens.push_back(token);
  }
  int idx = 0;
    return Helper(tokens,idx);
}
void inorder(Node* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
string s;
getline(cin,s);
 // Deserialize
    Node* newRoot = Deserialize(s);

    cout << "\nInorder After Deserialization:\n";
    inorder(newRoot);

    cout << endl;
return 0; 
}