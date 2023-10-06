
void countNodesDFS(vector<vector<int>> &adj, vector<int> &arr, int src, int parent)
{
	arr[src] = 1;
	for(auto it = adj[src].begin();it!= adj[src].end();++it)
	{
		if(*it == parent) continue;

		countNodesDFS(adj, arr, *it, src);
		arr[src]+= arr[*it];
	}
}

vector<int> countNodesInAllSubtrees(int n, vector<vector<int>> &adj) {
	// Write your code here.
	// adj[i] will contain all nodes adjacent to the ith node(0-based indexing)

	vector<int>ans(n);
	countNodesDFS(adj,ans,0,-1);
	return ans;
}

