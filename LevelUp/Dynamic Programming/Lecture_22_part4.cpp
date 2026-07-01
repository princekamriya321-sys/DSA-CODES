#include<bits/stdc++.h>
using namespace std;

int countSubsequences(string s)
{
long long ea = 0;
long long eb = 0;
long long ec = 0;
long long mod = 1e9+7;
for(int i =0; i<s.size(); i++){
    if(s[i] == 'a'){
        ea = (ea*2 + 1)%mod;
        } else if(s[i] == 'b'){
            eb = (eb*2 + ea)%mod;
        } else {
            ec = (ec*2 + eb)%mod;
        }
}
return (int)ec;
}

int main()
{
    string s;
    cin >> s;

    cout << countSubsequences(s);

    return 0;
}