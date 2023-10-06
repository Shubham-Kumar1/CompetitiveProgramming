#include<bits/stdc++.h>

using namespace std;
//n = 10^5
vector<int> ar[100001];
bool vis[100001];

void dfs(int node){
	vis[node] = true;
	cout<<node<<" ";

	for(int v : ar[node]){

		if(vis[v] == false) dfs(v);
	}
}

int main(){

	int n , m;
	int a , b;

	cin>>n>>m;

	//initialize vis[]
	for(int i=1;i<=n;i++) vis[i] = false;

	//graph input
	for(int i=1;i<=m;i++){
		cin>>a>>b;

		ar[a].push_back(b);
		ar[b].push_back(a);
	}

	dfs(1);

}
