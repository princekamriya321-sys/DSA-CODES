#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
int n,k;
cin>>n>>k;
vector<int> arr(n);
unordered_map<int,int> mp;
for(int i = 0; i<n; i++){
    cin>>arr[i];
    mp[arr[i]]++;
}
bool ans = false;
for(int i = 0; i<n; i++){
    int a = arr[i];
    int b = k-a;
    if(a != b && mp.find(b) != mp.end()){
        ans = true;
    } else if(a == b && mp[b] >= 2){
        ans = true;
    }
}
cout<<ans<<endl;
return 0;
}