#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> NSEonright(vector<int> &arr){
int n = arr.size();
vector<int> ans(n);
stack<int> st;
for(int i =0; i<n; i++){
    while(st.size()>0 && arr[i] < arr[st.top()]){
        int idx = st.top();
        st.pop();
        ans[idx] = arr[i];
    }
    st.push(i);
}
while(st.size()>0){
    int idx = st.top();
    st.pop();
    ans[idx] = -1;
}
return ans;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
vector<int> ans = NSEonright(arr);
for(int x: ans){
    cout<<x<<" ";
}
return 0;
}