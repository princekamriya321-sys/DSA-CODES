#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
int n;
cin>>n;
vector<int> arr(n);
// Check is their exit the duplicates in the number unordered_set help me only stores one time it's value if dulplicate then it not store the value
unordered_set<int> st;
for(int i = 0; i<n; i++){
    cin>>arr[i];
    st.insert(arr[i]);
}
int ans = 0;
for(auto it : st){
ans++;
}
cout<<ans<<endl;
return 0;
}