#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int singleelement1(vector<int> &arr){
    int n = arr.size();
    int ans = 0;
    for(int i =0; i<n; i++){
        ans = ans^arr[i];
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
int ans = singleelement1(arr);
cout<<ans<<endl;
return 0;
}