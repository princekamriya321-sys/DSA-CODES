#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void type1(vector<int> &arr,int i){
    int n = arr.size();
    if(arr[i] == 0){
        arr[i] = 1;
    } else {
        arr[i] = 0;
    }
}
int type2(vector<int> &arr,int i){
int ldist = 0;
int lidx = 0;
int ridx = 0;
int rdist = 0;
int n = arr.size();
for(int j =i ; j>=0; j--){
if(arr[j] == 1){
    ldist = i-j+1;
    lidx = j;
    break;
}
}
for(int j = i ; j<n; j++){
if(arr[j] == 1){
    rdist = j-i+1;
    ridx = j;
    break;
}
}
if(ldist<rdist){
    return lidx;
} else {
    return ridx;
}
}
int main() {
int n,i;
cin>>n>>i;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
type1(arr,i);
int idx = type2(arr,i);
cout<<idx<<endl;
return 0; 
}