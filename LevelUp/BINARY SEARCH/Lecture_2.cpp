#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int calculate(vector<int> &time,int m){
  int days = 1;
  int sum = 0;
  for(int w : time){
    if(sum + w > m){
        days++;
        sum = w;
    } else {
    sum += w;
    }
  }
  return days;
}
int painterspartition(vector<int> &time,int workers){
int lo = 0; 
int hi = 0;
for(int v: time){
    lo = max(lo,v);
    hi += v;
}
int ans = 0;
while(lo<=hi){
    int m = lo + (hi-lo)/2;
    int reqworker = calculate(time,m);
    if(reqworker <= workers){
    ans = m;
    hi = m-1;
    } else {
    lo = m+1;
    }
}
return ans;
}
int main() {
int n,wk;
cin>>n>>wk;
vector<int> time(n);
for(int i =0; i<n; i++){
    cin>>time[i];
}
int ans = painterspartition(time,wk);
cout<<ans<<endl;
return 0; 
}