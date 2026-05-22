#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool ispalindrome(string s,int sp,int ep){
   if(sp >= ep){ return true;}
   if(s[sp] != s[ep]){ return false; 
   } else {
   bool t = ispalindrome(s,sp+1,ep-1);
     return t;
   }
}

int main() {
string s;
cin>>s;
bool ans = ispalindrome(s,0,s.size()-1);
cout<<ans<<endl;
return 0;
}