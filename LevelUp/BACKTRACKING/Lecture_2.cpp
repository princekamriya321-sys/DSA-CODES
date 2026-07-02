#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void subsetsum(vector<int>&arr,int k,int i,int sum){
    if(i == arr.size()){
     if(sum == k) ans++;
     return;
    }
    subsetsum(arr,k,i+1,sum+arr[i]); // pick
    subsetsum(arr,k,i+1,sum); // don't pick
}
int countSubsets(vector<int> &arr, int K)
{
    int sum = 0;
subsetsum(arr,K,0,sum);
return ans;
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

    cout << countSubsets(arr, K);

    return 0;
}