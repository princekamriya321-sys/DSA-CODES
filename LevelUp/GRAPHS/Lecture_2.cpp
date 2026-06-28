#include<bits/stdc++.h>
using namespace std;

class pair1{
public:
    int v;
    int wt;

    pair1(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

class pair2{
public:
    int vtx;
    int wsf;

    pair2(int vtx,int wsf){
        this->vtx=vtx;
        this->wsf=wsf;
    }
};

class Compare{
public:
    bool operator()(const pair2 &a,const pair2 &b) const{
        return a.wsf>b.wsf;
    }
};

vector<int> dijkstra(vector<vector<pair1>> &graph,int V,int src){

    priority_queue<pair2,vector<pair2>,Compare> pq;

    vector<int> ans(V,INT_MAX);

    pq.push(pair2(src,0));

    while(!pq.empty()){

        pair2 rem=pq.top();
        pq.pop();

        if(ans[rem.vtx]!=INT_MAX)
            continue;

        ans[rem.vtx]=rem.wsf;

        for(auto &n:graph[rem.vtx]){

            if(ans[n.v]!=INT_MAX)
                continue;

            pq.push(pair2(n.v,rem.wsf+n.wt));
        }
    }

    return ans;
}

int main(){

    int V=7;

    vector<vector<pair1>> graph(V);

    graph[0].push_back(pair1(1,20));
    graph[1].push_back(pair1(0,20));

    graph[1].push_back(pair1(2,28));
    graph[2].push_back(pair1(1,28));

    graph[2].push_back(pair1(3,40));
    graph[3].push_back(pair1(2,40));

    graph[0].push_back(pair1(3,10));
    graph[3].push_back(pair1(0,10));

    graph[3].push_back(pair1(4,50));
    graph[4].push_back(pair1(3,50));

    graph[4].push_back(pair1(5,60));
    graph[5].push_back(pair1(4,60));

    graph[5].push_back(pair1(6,70));
    graph[6].push_back(pair1(5,70));

    graph[4].push_back(pair1(6,80));
    graph[6].push_back(pair1(4,80));

    vector<int> ans=dijkstra(graph,V,0);

    for(int i=0;i<V;i++)
        cout<<i<<" -> "<<ans[i]<<endl;
}