#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Totalsum(vector<int> &arr){
int n = arr.size();
int ans = 0;
for(int i = 0; i<n; i++){
    int s = i+1;
    int e = n-i;
    int occ = s*e;
    ans += occ*arr[i];
}
return ans;
}
int main() {
int n;  
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
int ans = Totalsum(arr);
cout<<ans<<endl;
return 0;
}