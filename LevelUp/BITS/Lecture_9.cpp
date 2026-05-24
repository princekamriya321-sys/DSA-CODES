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
int a = 0;
for(int i =0; i<n; i++){
    a = a^arr[i];
}
int idx = 0;
for(int i = 0; i<32; i++){
    if(checkbit(a,i)){
        idx = i;
        break;
    }
}
int set1 = 0;
int set2 = 0;
for(int i = 0; i<n; i++){
    int num = arr[i];
    if(checkbit(num,idx)){
        set2 = set2^num;
    } else {
        set1 = set1^num;
    }
}
cout<<set1<<" "<<set2<<endl;
return 0;
}