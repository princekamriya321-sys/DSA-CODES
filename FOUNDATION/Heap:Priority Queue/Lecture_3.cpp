#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
vector<int> arr(n);
priority_queue<int> pq;
for(int i = 0; i<n; i++){
    cin>>arr[i];
    pq.push(arr[i]);
}
for(int i = 1; i<k; i++){
    pq.pop();
}
cout<<pq.top();
return 0;
}