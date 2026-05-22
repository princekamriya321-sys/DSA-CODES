#include<iostream>
// #include<bits/stdc++.h>
#include<queue>
using namespace std;
string kthPalindrome(int k){
queue<string> q;
string ans = "";
q.push("11");
q.push("22");
for(int i = 1; i<=k; i++){
    string temp = q.front();
      q.pop();
    if(k == i){ ans = temp;}
    string left = temp.substr(0,temp.size()/2);
    string right = temp.substr(temp.size()/2, temp.size());
    q.push(left+"11"+right);
    q.push(left+"22"+right);
}
return ans;
}
int main(){
int k;
cin>>k;
string ans = kthPalindrome(k);
cout<<ans<<endl;
return 0;
 }