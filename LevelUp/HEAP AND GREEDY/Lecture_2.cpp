#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<pair<int,int>> events;

    // Create events
    for(auto &b : buildings)
    {
        events.push_back({b[0], -b[2]}); // Start
        events.push_back({b[1],  b[2]}); // End
    }

    sort(events.begin(), events.end());

    multiset<int> heights;

    heights.insert(0);

    int prevHeight = 0;

    vector<vector<int>> ans;

    for(auto event : events)
    {
        int x = event.first;
        int h = event.second;

        if(h < 0)
        {
            // Start of building
            heights.insert(-h);
        }
        else
        {
            // End of building
            heights.erase(heights.find(h));
        }

        int currHeight = *heights.rbegin();

        if(currHeight != prevHeight)
        {
            ans.push_back({x, currHeight});
            prevHeight = currHeight;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> buildings(n, vector<int>(3));

    for(int i=0;i<n;i++)
    {
        cin>>buildings[i][0]
            >>buildings[i][1]
            >>buildings[i][2];
    }

    vector<vector<int>> ans = getSkyline(buildings);

    for(auto &x : ans)
    {
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}