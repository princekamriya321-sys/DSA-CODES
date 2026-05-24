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
int ans = 0;
for(int i =0; i<32; i++){
    int count = 0;
    for(int j = 0; j<n; j++){
bool a = checkbit(arr[j],i);
if(a){
    count++;
}
    }
    if(count%3 == 1){
ans = ans + (1<<i);
    } else {
    }
}
cout<<ans<<endl;
return 0;
}