#include<iostream>
// #include<bits/stdc++.h>
#include<queue>
using namespace std;
string kthnumber(int k){
queue<string> q;
string ans = "";
q.push("1");
q.push("2");
for(int i = 1; i<=k; i++){
    string curr = q.front();
      q.pop();
    if(k == i){ ans = curr;}
q.push(curr + "1");
q.push(curr+"2");
}
return ans;
}
int main(){
int k;
cin>>k;
string ans = kthnumber(k);
cout<<ans<<endl;
return 0;
 }