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
int Patternsearch(string s,string p, vector<int> lps){
    int n = s.size();
    int m = p.size();
    int count = 0;
    for(int i = 0; i<n; i++){
if(m == lps[i]){
    count++;
}
    }
    return count;
}
int main() {
string t,p;  
cin>>t>>p;
string s = p+"#" + t;
vector<int> lps = LPS(s);
int ans = Patternsearch(s,p,lps);
cout<<ans<<endl;
return 0;
}