#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int fibbo(int n){
if(n <= 1){
return n;
}
if(dp[n] != -1){
    return dp[n];
}
int a = fibbo(n-1);
int b = fibbo(n-2);
dp[n] = a + b;
return dp[n];
}
int main(){
int n;
cin>>n;
dp.resize(n+1,-1);
int ans = fibbo(n);
cout<<ans<<endl;
return 0;
}
