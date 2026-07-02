#include<bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> &deadline, vector<int> &payment)
{
    int n = deadline.size();
    vector<pair<int,int>> arr;
    for(int i = 0; i<n; i++){
        arr.push_back({deadline[i],payment[i]});
    }
sort(arr.begin(),arr.end());
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
for(int i =0; i<n; i++){
    if(arr[i].first > pq.size()){
        pq.push(arr[i].second);
    } else {
        if(arr[i].second > pq.top()){
            pq.pop();
            pq.push(arr[i].second);
        }
    }
}
int sum = 0;
while(pq.size() > 0){
    sum += pq.top();
    pq.pop();
}
return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> deadline(n);
    vector<int> payment(n);

    cout << "Enter deadlines:\n";
    for(int i = 0; i < n; i++)
        cin >> deadline[i];

    cout << "Enter payments:\n";
    for(int i = 0; i < n; i++)
        cin >> payment[i];

    cout << jobScheduling(deadline, payment);

    return 0;
}