#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Generatebinary(int n){
queue<string> q;
q.push("1");
while(n>0){
    string rem = q.front();
    q.pop();
    cout<<rem<<" ";
    q.push(rem+ "0");
    q.push(rem + "1");
    n--;
}
}
int main() {
int n;
cin>>n;
Generatebinary(n);
return 0; 
}