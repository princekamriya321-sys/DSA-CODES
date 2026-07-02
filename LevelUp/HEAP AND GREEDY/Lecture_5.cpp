#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> &start, vector<int> &end)
{
    vector<pair<int,int>> arr;
    for(int i =0; i<start.size(); i++){
        arr.push_back({start[i],end[i]});
    }
sort(arr.begin(),arr.end(),[](auto &a,auto &b){
return a.second < b.second;
});
int ans = 1;
int currtime = arr[0].second;
for(int i =1; i<arr.size(); i++){
    if(arr[i].first >= currtime){
        ans++;
        currtime = arr[i].second;
    }
}
return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> start(n);
    vector<int> end(n);

    cout << "Enter start times:\n";
    for(int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter end times:\n";
    for(int i = 0; i < n; i++)
        cin >> end[i];

    cout << activitySelection(start, end);

    return 0;
}