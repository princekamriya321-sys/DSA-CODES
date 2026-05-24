#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool checkbit(int n,int r){
    int x = 1<<r;
    if(n & x){
        return true;
    } else {
        return false;
    }
}
int unsetbit(int n,int r){
    int x = 1<<r;
    bool ans = checkbit(n,r);
    int t = n;
    if(ans){
    t = n ^ x;
    }

    return t;
}
int main() {
int n,r;
cin>>n>>r;
int ans = unsetbit(n,r);
cout<<ans<<endl;
return 0;
}