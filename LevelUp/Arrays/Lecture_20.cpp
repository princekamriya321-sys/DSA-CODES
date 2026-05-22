#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Nextgreatelement(string s){
    int n = s.size();
    int idx = -1;
    for(int i = n-2; i>=0; i--){
        if(s[i] < s[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        return -1;
    }
    char val = s[idx];
    int smallestidx = idx + 1;
    for(int i = idx+1; i<n; i++){
        if(s[i]>val && s[i]<=s[smallestidx]){
            smallestidx = i;
        }
    }
    int temp = s[idx];
    s[idx] = s[smallestidx];
    s[smallestidx] = temp;
    sort(s.begin()+idx+1,s.end());
    long long ans = stoll(s);
    if(ans > INT_MAX){
        return -1;
    } else {
        return (int)ans;
    }
}
int main() {
string s; 
cin>>s;
int ans = Nextgreatelement(s);
    cout<<ans;
return 0;
}