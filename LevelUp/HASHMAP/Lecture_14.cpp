#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool anagrampalindrome(string s){
unordered_map<char,int> mp;
for(int i =0; i<s.size(); i++){
    mp[s[i]]++;
}
int ct = 0;
bool ans = true;
for(auto it: mp){
    if(it.second %2 != 0){
ct++;
    }
}
if(ct == 1 && s.size()%2 != 0){
    ans = true;
} else if(ct> 1){
    ans = false;
} else if(ct == 1 && s.size()%2 == 0){
    ans = false;
}
return ans;
}
int main() {
string s;
cin>>s;
bool ans = anagrampalindrome(s);
cout<<ans;
return 0;
}