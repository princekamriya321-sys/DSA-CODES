#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool checkbit(int n,int i){
    int x = 1<<i;
    if(n&x){
        return true;
    } else {
        return false;
    }
}
int main() {
int n;
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
for(int i =31; i>=0; i--){
    int ct = 0;
for(int j =0; j<n; j++){
    bool a = checkbit(arr[j],i);
    if(a){
        ct++;
    }
}
if(ct>=2){
    for(int j = 0; j<n; j++){
bool a = checkbit(arr[j],i);
if(a == false){
    arr[j] = 0;
}
    }
}
}
int idx1 = -1;
int idx2 = -1;
for(int j = 0;j<n; j++){
    if(arr[j]>0 && idx1 == -1){
        idx1 = j;
    } else if(arr[j]>0 && idx1 != -1){
        idx2 = j;
        break;
    } 
}
int ans= arr[idx1] & arr[idx2];
cout<<ans<<endl;
return 0;
}