#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int minsq(int n){
if(n <= 1){
return n;
}
if(dp[n] != -1){
    return dp[n];
}
int smallest = INT_MAX;
for(int i = 1; i*i<=n; i++){
    int temp = minsq(n - i*i);
    smallest = min(smallest,temp);
}
dp[n] = smallest + 1;
return dp[n];
}
int main(){
int n;
cin>>n;
dp.resize(n+1,-1);
int ans = minsq(n);
cout<<ans<<endl;
return 0;
}
