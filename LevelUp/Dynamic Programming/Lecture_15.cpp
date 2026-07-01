#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
   int maxp = 0;
   int minbp = prices[0];
   for(int v :  prices){
    int tp = v - minbp;
    if(tp > maxp){
       maxp = tp;
    }
    minbp = min(minbp,v);
   }
return maxp;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices);

    return 0;
}