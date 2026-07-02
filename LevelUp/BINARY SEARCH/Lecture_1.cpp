#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int calculate(vector<int> &weight,int m){
    int days = 1;
    int sum = 0;
    for(int w : weight){
        if(sum + w > m){
days++;
sum = 0;
        } else {
            sum += w;
        }
    }
    return days;
}
int capacitytoshippackages(vector<int> &weight,int days){
    int lo = 0;
    int hi = 0;
    for(int v: weight){
        lo = max(lo,v);
        hi += v;
    }
    int ans = 0;
    while(lo <= hi){
        int m = lo + (hi-lo)/2;
int reqdays = calculate(weight,m);
if(reqdays <= days){
ans = m;
hi = m-1;
} else {
    lo = m+1;
}
    }
    return ans;
}
int main() {
int n,d;
cin>>n,d;
vector<int> weight(n);
for(int i =0; i<n; i++){
    cin>>weight[i];
}
int ans = capacitytoshippackages(weight,d);
cout<<ans<<endl;
return 0;
}