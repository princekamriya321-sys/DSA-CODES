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
Node* Construct(vector<int> &pre,int ps, int pe,vector<int> &in,int is, int ie){
if(ps>pe || is>ie) return NULL;
Node* root = new Node(pre[ps]);
int idx = 0;
for(int i = is; i<=ie; i++){
    if(in[i] == pre[ps]){ idx = i;
    break;
}
}
int count = idx - is;
root->left = Construct(pre,ps+1,ps+count,in,is,idx-1);
root->right = Construct(pre,ps+count+1,pe,in,idx+1,ie);
return root;
}
int main() {
int n,m;
cin>>n>>m;
vector<int> pre(n);
vector<int> in(n);
for(int i = 0; i<n; i++){
    cin>>pre[i];
}
for(int i = 0; i<n; i++){
    cin>>in[i];
}
Node* root = Construct(pre,0,n-1,in,0,m-1);
return 0; 
}