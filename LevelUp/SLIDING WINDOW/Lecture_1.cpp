#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr, int k)
{
   int n = arr.size();
   int sum = 0;
   for(int i =0; i<k; i++){
    sum += arr[i];
   }
   int ans = sum;
   int s = 1;
   int e = k;
   while(e<n){
    sum += arr[e] - arr[s-1];
ans = max(ans,sum);
s++;
e++;
   }
   return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    cout << maxSubarraySum(arr, k);

    return 0;
}