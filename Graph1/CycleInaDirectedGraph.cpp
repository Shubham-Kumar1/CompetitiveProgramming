
bool dfs(int node,vector<int> &visited,vector<int>adj[])
{
	visited[node] = 1;
	for(auto v : adj[node])
	{
		if(visited[v]==1) return true;
		if(visited[v]==0 && dfs(v,visited,adj)==true) return true;
	}
	visited[node]=2;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<int>visited(v,0);
	vector<int>adj[v];
	for(int i=0;i<edges.size();++i) adj[edges[i][0]].push_back(edges[i][1]);
	for(int i=0;i<v;++i)
	{
		if(visited[i]==0 && dfs(i,visited,adj)==true) return true;
	}
	return false;
}

