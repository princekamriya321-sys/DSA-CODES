#include<iostream>
// #include<bits/stdc++.h>
#include<queue>
using namespace std;
queue<int> Reversekelements(queue<int> q, int k){
int n = q.size();
stack<int> st;
for(int i = 0; i<k; i++){
    st.push(q.front());
    q.pop();
}
for(int i =0; i<k; i++){
    q.push(st.top());
    st.pop();
}
for(int i = 0; i<n-k; i++){
q.push(q.front());
q.pop();
}
return q;
}
int main(){
queue<int> q;
int k;
cin>>k;
q.push(3);
q.push(10);
q.push(2);
q.push(12);
q.push(19);
q.push(6);
q.push(8);
q.push(10);
q.push(14);
queue<int> ans = Reversekelements(q, k);
int n = q.size();
for(int i = 0; i<n; i++){
cout<<ans.front()<<" ";
ans.pop();
}
return 0;
 }