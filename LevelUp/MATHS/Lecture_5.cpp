#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a == 0)return b;
    int temp = gcd(b%a,a);
    return temp;
}
vector<int> func1(vector<int> &arr){
    int n = arr.size();
    vector<int> pgcd(n);
    pgcd[0] = arr[0];
    for(int i =1; i<n; i++){
pgcd[i] = gcd(arr[i],pgcd[i-1]);
    }
    return pgcd;
}
vector<int> func2(vector<int> &arr){
    int n = arr.size();
    vector<int> sgcd(n);
    sgcd[n-1] = arr[n-1];
    for(int i =n-2; i>=0; i--){
sgcd[i] = gcd(arr[i],sgcd[i+1]);
    }
    return sgcd;
}
int deletetomaximise(vector<int> &arr){
    int n = arr.size();
    vector<int> pgcd = func1(arr);
    vector<int> sgcd = func2(arr);
    int ans = 0;
    for(int i = 1; i<n-1; i++){
        int l = pgcd[i-1];
        int r = sgcd[i+1];
        ans = max(gcd(l,r),ans);
    }
    ans = max(pgcd[n-2],ans);
    ans = max(sgcd[1],ans);
    return ans;
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = deletetomaximise(arr);
cout<<ans<<endl;
return 0;
}