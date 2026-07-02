#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr, int b)
{
   int k =0;
   int n = arr.size();
   for(int i = 0; i<n; i++){
    if(arr[i]<=b) k++;
   }
int c = 0;
for(int i =0; i<k; i++){
    if(arr[i]<=b)c++;
}
int ans = k-c;
int s = 1;
int e = k;
while(e<n){
    if(arr[e]<=b) c++;
    if(arr[s-1] <= b) c--;
    ans = min(ans,k-c);
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

    cout << minSwaps(arr, k);

    return 0;
}