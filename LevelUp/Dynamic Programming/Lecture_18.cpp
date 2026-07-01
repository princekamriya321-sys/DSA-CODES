#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
   int buy = -prices[0];
   int sell = 0;
   int cooldown = 0;
   for(int i =1; i<prices.size(); i++){
    int nbuy = max(buy,cooldown - prices[i]);
    int nsell = max(sell,prices[i] + buy);
    cooldown = max(cooldown,sell);
    sell = nsell;
    buy = nbuy;
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

    cout << maxProfit(prices);

    return 0;
}