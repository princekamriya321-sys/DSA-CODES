#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string minwindowstring(string s,string p){
if(p.size()> s.size()){
    return "";
}
unordered_map<char,int> hmp;
unordered_map<char,int> hms;
for(int i =0; i<p.size(); i++){
    hmp[p[i]]++;
}
int matchcount = 0;
int anslen = INT_MAX;
int sp = 0;
int ep = 0;
int startidx = 0;
while(ep<s.size()){
if(matchcount == p.size()){
    if(ep-sp < anslen){
        anslen = ep - sp;
        startidx = sp;
    }

hms[s[sp]]--;
if(hmp.count(s[sp]) && hms[s[sp]] < hmp[s[sp]]){
    matchcount--;
}
sp++;
} else {
hms[s[ep]]++;
if(hmp.count(s[ep]) && hms[s[ep]] <= hmp[s[ep]]){
    matchcount++;
}
ep++;
}
while(matchcount == p.size()){
    if(ep - sp < anslen){
        anslen = ep - sp;
        startidx = sp;
    }
    hms[s[sp]]--;
    if(hmp.count(s[sp]) && hms[s[sp]] < hmp[s[sp]]){
        matchcount--;
    }
    sp++;
}
}
if(anslen == INT_MAX){
    return "";
}
return s.substr(startidx,anslen);
}
int main() {
string s,p;
cin>>s>>p;
string ans = minwindowstring(s,p);
cout<<ans<<endl;
return 0;
}