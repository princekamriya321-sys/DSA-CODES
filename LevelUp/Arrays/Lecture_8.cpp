#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> Prefixsum(vector<int> &arr){
int n = arr.size();
int sum = 0;
vector<int> prefixsum(n);
for(int i = 0; i<n; i++){
sum += arr[i];
prefixsum[i] = sum;
}
return prefixsum;
}
int main() {
int n;  
cin>>n;
vector<int> arr(n);
for(int i = 0; i<n; i++){
    cin>>arr[i];
}
vector<int> prefixsum = Prefixsum(arr);

for(int s = 0; s<n; s++){
    for(int e = s; e<n; e++){
        if(s == 0){
            cout<<prefixsum[e];
        } else {
            int sum = prefixsum[e] - prefixsum[s-1];
            cout<<sum<<" ";
        }
       
    }
}

return 0;
}