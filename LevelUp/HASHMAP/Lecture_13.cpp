#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> findanagrams(string s,string p){
    vector<int> ans;
if(p.size()> s.size()){
    return ans;
}
unordered_map<char,int> hmp;
unordered_map<char,int> hms;
for(int i =0; i<p.size(); i++){
    hmp[p[i]]++;
}
int matchcount = 0;
for(int i = 0; i<p.size(); i++){
    hms[s[i]]++;
    if(hms[s[i]] == hmp[p[i]]){
        matchcount++;
    }
}  
if(matchcount == p.size()){
    ans.push_back(0);
}
int sp= 0;
int ep= p.size();
while(ep<s.size()){
hms[s[ep]]++;
if(hms[s[ep]] <= hmp[s[ep]]){
    matchcount++;
}
hms[s[sp]]--;
if(hms[s[sp]] < hmp[s[sp]]){
    matchcount--;
}
sp++;
ep++;
if(matchcount == p.size()){
    ans.push_back(sp);
}
}
return ans;
}
int main() {
string s,p;
cin>>s>>p;
vector<int> ans = findanagrams(s,p);
for(int x : ans){
    cout<<x<<" ";
}
return 0;
}