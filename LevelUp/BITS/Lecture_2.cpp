#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int flipbit(int n,int r){
    int x = 1<<r;
    int ans = n ^ x;
    return ans;
}
int main() {
int n,r;
cin>>n>>r;
int ans = flipbit(n,r);
cout<<ans<<endl;
return 0;
}