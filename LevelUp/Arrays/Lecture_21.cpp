#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Maxchunks(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    int maxtillnow = INT_MIN;
    for(int i =0; i<n; i++){
        maxtillnow = max(maxtillnow,arr[i]);
        if(maxtillnow == i){
            count++;
        }
    }
   return count;
}
int main() {
int n; 
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = Maxchunks(arr);
cout<<ans<<endl;
return 0;
}