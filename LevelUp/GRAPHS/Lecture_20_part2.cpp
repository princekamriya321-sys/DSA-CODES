#include<bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    // Write your code here.
unordered_map<int,vector<int>> mp;
for(int i =0; i<routes.size(); i++){
    for(int j = 0; j<routes[i].size(); j++){
        int bus_stop = routes[i][j];
        vector<int> busno = mp[bus_stop];
        busno.push_back(i);
        mp[bus_stop].push_back(i);
    }
}
queue<pair<int,int>>q;//busstop,buscount
unordered_set<int> busvis;
unordered_set<int> busstopvis;
q.push({source,0});
busstopvis.insert(source);
while(q.size()>0){
auto rem = q.front();
q.pop();
if(rem.first == target) return rem.second;
vector<int> buses = mp[rem.first];
for(int bus: buses){
    if(busvis.count(bus)) continue;
    busvis.insert(bus);
for(auto it : routes[bus]){
  if(busstopvis.count(it))continue;
  q.push({it,rem.second+1});
  busstopvis.insert(it);
}
}
}
return -1;
}

int main()
{
    vector<vector<int>> routes = {
        {1,2,3},
        {1,4,5},
        {5,8,7},
        {3,6,7}
    };

    int source = 1;
    int target = 7;

    cout << "Routes:\n";

    for(int i = 0; i < routes.size(); i++)
    {
        cout << "Route " << i << " : ";

        for(int stop : routes[i])
            cout << stop << " ";

        cout << endl;
    }

    cout << "\nSource = " << source << endl;
    cout << "Target = " << target << endl << endl;

    cout << "Minimum Buses Required = "
         << numBusesToDestination(routes, source, target);

    return 0;
}