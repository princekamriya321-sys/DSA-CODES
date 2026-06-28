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

int Primsalgo(vector<vector<pair1>> &graph,int V,int src){

    priority_queue<pair2,vector<pair2>,Compare> pq;

    vector<int> vis(V,INT_MAX);

    pq.push(pair2(src,0));

    while(!pq.empty()){

        pair2 rem=pq.top();
        pq.pop();

        if(vis[rem.vtx]!=INT_MAX)
            continue;

        vis[rem.vtx]=rem.wsf;

        for(auto &n:graph[rem.vtx]){

            if(vis[n.v]!=INT_MAX)
                continue;

            pq.push(pair2(n.v,n.wt));
        }
    }
    int sum = 0;
for(int i =0; i<vis.size(); i++){
sum += vis[i];
}
    return sum;
}

int main(){

    int V = 4;

    vector<vector<pair1>> graph(V);

    graph[0].push_back(pair1(1,16));
    graph[1].push_back(pair1(0,16));

    graph[1].push_back(pair1(2,13));
    graph[2].push_back(pair1(1,13));

    graph[2].push_back(pair1(3,12));
    graph[3].push_back(pair1(2,12));

    graph[0].push_back(pair1(3,10));
    graph[3].push_back(pair1(0,10));

    graph[0].push_back(pair1(2,14));
    graph[2].push_back(pair1(0,14));

    int ans= Primsalgo(graph,V,0);
        cout<<ans<<endl;
}