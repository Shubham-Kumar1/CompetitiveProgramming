#include<bits/stdc++.h>

using namespace std;

//n = 10^5
vector<int> ar[100001];
bool vis[100001];
int dist[100001];

void bfs(int src){
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	vis[src] = true;

	while(q.empty() == false){
		int node = q.front();
		q.pop();

		cout<<node<<" ";

		for(int v : ar[node]){
			if(vis[v] == false){
				dist[v] = dist[node] + 1;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

int main(){

	int n , m;
	int a , b;

	cin>>n>>m;

	for(int i=1;i<=n;i++) vis[i] = false;

	for(int i=1;i<=m;i++){
		cin>>a>>b;

		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	bfs(1);
	cout<<endl;

	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

}
