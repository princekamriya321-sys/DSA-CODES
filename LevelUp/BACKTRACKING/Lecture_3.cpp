#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void subsetsum(vector<int>&arr,int k,int i,int sum){
    if(i == arr.size()){
     if(sum == k){
        for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
        }
     }
     return;
    }
    ans.push_back(arr[i]);
    subsetsum(arr,k,i+1,sum+arr[i]); // pick
    ans.pop_back();
    subsetsum(arr,k,i+1,sum); // don't pick
}
void printSubsets(vector<int> &arr, int K)
{
    int sum = 0;
subsetsum(arr,K,0,sum);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int K;
    cin >> K;

   printSubsets(arr, K);

    return 0;
}