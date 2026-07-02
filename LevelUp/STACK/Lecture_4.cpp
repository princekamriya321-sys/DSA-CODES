#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> func1(vector<int> &arr){
int n = arr.size();
vector<int> ans(n);
stack<int> st;
for(int i =0; i<n; i++){
    while(st.size()>0 && arr[i] < arr[st.top()]){
        int idx = st.top();
        st.pop();
        ans[idx] = i;
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
vector<int> func2(vector<int> &arr){
int n = arr.size();
vector<int> ans(n);
stack<int> st;
for(int i =n-1; i>=0; i--){
    while(st.size()>0 && arr[i] < arr[st.top()]){
        int idx = st.top();
        st.pop();
        ans[idx] = i;
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
int LAH(vector<int> &arr){
    int n = arr.size();
    vector<int> nseonright = func1(arr);
    vector<int> nseonleft = func2(arr);
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
int ht = arr[i];
int x1 =nseonright[i] - 1;
int x2 = nseonleft[i] + 1;
int wd = x1 -x2 + 1;
int area = ht*wd;
ans = max(ans,area);
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
int ans = LAH(arr);
cout<<ans;
return 0;
}