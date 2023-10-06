#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
vector<int>tree[N+1];
int bfs(int root)
{
	int cnt=0;
	vector<bool>visited(N,false);
	visited[root] = true;
	queue<int>q;
	q.push(root);

	while(!q.empty())
	{
		cnt++;
		int u = q.front();
		q.pop();

		for(int v : tree[u])
		{
			if(!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
	return cnt;
}

int main() {
	int n,m; cin >> n >> m;
	for(int i=0;i<m;++i)
	{
		int u,v; cin >> u >> v;
		tree[u].push_back(v);
        tree[v].push_back(u);
    }
	int cnt = bfs(1);
	if(cnt==n) cout << "YES" << endl;
	else cout << "NO" << endl;
}
