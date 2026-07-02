#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Maxfreqstack{
    public: 
    unordered_map<int,stack<int>>st;
    unordered_map<int,int>fmap;
    int maxfreq = 0;
void push(int val){
        int f = fmap[val];
        f++;
fmap[val] = f;
maxfreq = max(maxfreq,f);
st[f].push(val);
}
int pop(){
    int ans = st[maxfreq].top();
    st[maxfreq].pop();
    int f = fmap[ans];
    f--;
    fmap[ans] = f;
    if(st[maxfreq].size() == 0){
        st.erase(maxfreq);
        maxfreq--;
    }
    return ans;
}
};
int main() {
Maxfreqstack s1;
s1.push(2);
s1.push(4);
s1.push(6);
s1.push(4);
s1.push(2);
s1.push(6);
s1.push(8);
s1.push(2);

int a = s1.pop();
int b = s1.pop();
int c = s1.pop();
cout<<a<<" "<<b<<" "<<c<<endl;

return 0;
}