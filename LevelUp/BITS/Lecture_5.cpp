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
int n;
cin>>n;
int count = 0;
for(int i = 0; i<32; i++){
bool ans = checkbit(n,i);
if(ans){
    count++;
}
}
cout<<count<<endl;
return 0;
}