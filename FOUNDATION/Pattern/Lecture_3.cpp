#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
cin>>n;
int st = 1;
int sp = n/2;
for(int i = 1; i<=n; i++){
for(int j = 1; j<=sp; j++){
    cout<<" ";
}
for(int j = 1; j<=st; j++){
    cout<<"*";
}
if(i<=n/2){
    st+= 2;
    sp -= 1;
} else {
    st -= 2; 
    sp += 1;
}
cout<<endl;
}
return 0;
}