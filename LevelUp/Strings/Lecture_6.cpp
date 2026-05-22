#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int LPS(string s,int m){
int n = s.size();
vector<int> lps(n);
lps[0] = 0;
int ans = 0;
for(int i =1; i<n; i++){
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
return m-lps[n-1];
}
int main() {
string s1;  
cin>>s1;
string t = s1;
int n = s1.size();
reverse(s1.begin(),s1.end());
string s = t+"#"+s1;
int ans = LPS(s,n);
cout<<ans<<endl;
return 0;
}