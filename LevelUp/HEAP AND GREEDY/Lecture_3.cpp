#include<bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    priority_queue<int> pq;
   int curr = startFuel;
   int i =0; 
   int ct = 0;
   while(curr<target){
    while(i<stations.size() && stations[i][0] <= curr){
        pq.push(stations[i][1]);
        i++;
    }
    if(pq.size() == 0) return -1;
    curr = curr + pq.top();
    pq.pop();
    ct++;
   }
return ct;
}

int main()
{
    int target, startFuel;
    cin >> target >> startFuel;

    int n;
    cin >> n;

    vector<vector<int>> stations(n, vector<int>(2));

    // Input format:
    // position fuel
    for(int i = 0; i < n; i++)
    {
        cin >> stations[i][0] >> stations[i][1];
    }

    cout << minRefuelStops(target, startFuel, stations);

    return 0;
}