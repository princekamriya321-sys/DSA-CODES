#include<bits/stdc++.h>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return (double)a[0] / a[1] >
           (double)b[0] / b[1];
}
double fractionalKnapsack(vector<vector<int>> &items, int W)
{
   sort(items.begin(),items.end(),cmp);
   double ans = 0;
   for(int i =0; i<items.size(); i++){
    int val = items[i][0];
    int wt = items[i][1];
    if(W >= wt){
        ans += val;
        W -= wt;
    } else {
         ans += ((double)val/wt) * W;
            break;
    }
   }
   return ans;
}

int main()
{
    int n;
    cin >> n;

    // items[i][0] = value
    // items[i][1] = weight
    vector<vector<int>> items(n, vector<int>(2));

    for(int i = 0; i < n; i++)
    {
        cin >> items[i][0] >> items[i][1];
    }

    int W;
    cin >> W;

    cout << fixed << setprecision(2);
    cout << fractionalKnapsack(items, W);

    return 0;
}