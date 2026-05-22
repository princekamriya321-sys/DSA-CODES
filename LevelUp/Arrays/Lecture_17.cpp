#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Missingpositivenumber(vector<int> &arr){
    int i =0;
    int n = arr.size();
    while(i<n){
        if(arr[i]<1 || arr[i]>n || i == arr[i] - 1){
            i++;
        } else {
            int idx = arr[i] - 1;
            if(arr[i] == arr[idx]){ i++;
            } else {
            int temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
            }
        }
    }
  for(int i = 0; i<n; i++){ 
    if(i != arr[i]-1){
return i+1;
    }
  }
  return n+1;
}
int main() {
int n; 
cin>>n;
vector<int> arr(n);
for(int i =0; i<n; i++){
    cin>>arr[i];
}
int ans = Missingpositivenumber(arr);
cout<<ans<<endl;
return 0;
}