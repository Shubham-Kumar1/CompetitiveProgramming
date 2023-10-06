#include<bits/stdc++.h>
using namespace std;
void dijkstra(int n,int src,vector<int> &dist,vector<pair<int,int>> adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(dist[node] < d) continue;

        for(pair<int,int> e : adj[node])
        {
            if(dist[e.first] > d + e.second)
            {
                dist[e.first] = d + e.second;
                pq.push({dist[e.first],e.first});
            }
        }
    }
}
int main(){
    
    // write your code here
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;++i)
        {
            int a,b,c; cin >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        vector<int>dist(n,1e9);
        dijkstra(n,0,dist,adj);
        for(int i=0;i<n;++i)
        {
            cout << i <<" " << dist[i] << endl;
        }
    }
    return 0;
}
