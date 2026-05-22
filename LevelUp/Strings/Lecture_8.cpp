#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> LPS(string s){
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    for(int i = 1; i<n; i++){
        int len = lps[i-1];
        if(s[i] == s[len]){
lps[i] = len+1;
        } else {
            while(s[i] != s[len]){
                if(len == 0){
                    len = -1;
                    break;
                }
                len = lps[len-1];
            }
            lps[i] = len+1;
        }
    }
    return lps;
}
int main() {
string s;  
cin>>s;
vector<int> lps = LPS(s);
for(int x: lps){
    cout<<x<<" ";
}
return 0;
}