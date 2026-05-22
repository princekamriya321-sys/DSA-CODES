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
int ans = -1;
for(int i = 0; i<n; i++){
    if(freq[arr[i]] == 1){
        ans = arr[i];
        break;
    }
}
cout<<ans<<endl;
return 0;
}