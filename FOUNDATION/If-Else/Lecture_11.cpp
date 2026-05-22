#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
int count = 0;
for(int i = 2; i<n; i++){
    if(n%i == 0){
        count++;
    }
}
if(count == 0){
    if(n == 1 || n == 0){
        cout<<"Non Prime Number";
    } else {
    cout<<"Prime Number";}
} else {
    cout<<"Non Prime Number";
}
return 0;
}