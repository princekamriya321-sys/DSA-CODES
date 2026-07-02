#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int LAH(vector<int> &arr){
    int n = arr.size();
   stack<int> st;
    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
while (st.size()>0 && arr[i] < arr[st.top()]){
    int tbs = st.top();
    st.pop();
    int nsr = i;
    int x1 = nsr - 1;
    int nsl = -1;
    if(st.size()== 0){
nsl = -1;
    } else {
        nsl = st.top();
    }
    int x2 = nsl+1;
    int area = arr[tbs]*(x1-x2 + 1);
    ans = max(ans,area);
}
st.push(i);
}
while(st.size()>0){

    int tbs = st.top();
    st.pop();

    int nsr = n;

    int nsl = (st.size()==0 ? -1 : st.top());

    int area = arr[tbs] * (nsr - nsl - 1);

    ans = max(ans, area);
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