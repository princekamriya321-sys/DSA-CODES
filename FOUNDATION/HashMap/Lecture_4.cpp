#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
vector<int> arr(n);
unordered_map<int,int> freq;
for(int i = 0; i<n; i++){
    cin>>arr[i];
    freq[arr[i]]++;
}
for(auto it : freq){
    cout<<it.first<<"->"<<it.second<<endl;
}
return 0;
}