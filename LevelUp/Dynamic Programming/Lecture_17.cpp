#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
  int buy = -prices[0];
  int sell =0;
  for(int i = 1; i<prices.size(); i++){
int nbuy = max(buy,sell - prices[i]);
int nsell = max(sell,prices[i] + buy - fee);
buy = nbuy;
sell = nsell;
}
return sell;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    int fee;
    cin >> fee;

    cout << maxProfit(prices, fee);

    return 0;
}