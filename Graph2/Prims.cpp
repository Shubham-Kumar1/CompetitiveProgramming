#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void primsMST(int n , int src, vector<int> min_w, vector<pair<int,int>> adj[], vector<bool> &selected){
	int mstCost = 0;
	set<pair<int,int> > edgeSet;
	edgeSet.insert({0 , src});

	for(int i=0;i<n;i++){
		int node = edgeSet.begin()->second;
		int w = edgeSet.begin()->first;
		edgeSet.erase(edgeSet.begin());

		mstCost += w;
		selected[node] = true;

		for(pair<int,int> e : adj[node]){
			if(selected[e.first] == false && e.second < min_w[e.first]){
				edgeSet.erase({min_w[e.first] , e.first});
				min_w[e.first] = e.second;
				edgeSet.insert({min_w[e.first] , e.first});
			}
		}

	}
    cout << mstCost << endl;
}

int main(){
    int t; cin >> t;
    while(t--)
    {
	int n , m, a , b , w; cin>>n>>m;
    vector<int>min_w(n,INF);
    vector<pair<int,int>>adj[n];
    vector<bool>selected(n,false);
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		adj[a].push_back({b , w});
        adj[b].push_back({a, w});
        }
        primsMST(n, 0,min_w,adj,selected);
    }
}
