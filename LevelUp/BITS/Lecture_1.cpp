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
int main() {
int n,r;
cin>>n>>r;
bool ans = checkbit(n,r);
if(ans){
    cout<<"SET"<<endl;
} else {
    cout<<"UNSET"<<endl;
}
return 0;
}