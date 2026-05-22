#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
string s;
cin>>s;
int sp = 0;
int end = s.size() - 1;
while(sp < end){
    char temp = s[sp];
    s[sp] = s[end];
    s[end] = temp;
    sp++;
    end--;
}
cout<<s<<endl;
return 0;
