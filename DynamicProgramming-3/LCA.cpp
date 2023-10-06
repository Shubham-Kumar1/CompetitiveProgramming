// lowest common ancestor

#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int LGN = 20;
vector<int>g[N];
int dp[LGN][N];
int heights[N];

void dfs(int s, int p, int h=0){
	heights[s] = h;
	dp[0][s] = p;

	for(int i=1;i<LGN;++i){
		dp[i][s] = dp[i-1][dp[i-1][s]];
	}

	for(int v : g[s]){
		if(v!=p){
			dfs(v,s,h+1);
		}
	}
}

int lift(int u, int h){ // lift the node u by height h
	for(int i=0;i<LGN;++i){
		if(h & (1 << i)) u =dp[i][u];
	}
	return u;
}

int lca(int u, int v){
	// we are assuming always that height[u] > height[v] always so if not we will swap
	if(heights[u] < heights[v]) swap(u,v);
	// now the height of u will be greater than the the v
	u = lift(u,heights[u] - heights[v]); // if height of u is greater than the v then its time to lift

	if(u==v) return u;

	for(int i=LGN-1;i>=0;--i){
		if(dp[i][u] != dp[i][v]){
			u = dp[i][u];
			v = dp[i][v];
		}
	}
	return dp[0][u];
}



vector<int> lca(int n, vector<vector<int>> edge, vector<vector<int>> query)
{
	// the answer will be stored here
	vector<int> ans;

	// clearing the data structure for the previous testcases
	for(int i=0;i<N;++i){
		heights[i]=0;
		g[i].clear();
		for(int j=0;j<LGN;++j) dp[j][i] = 0;
	}

	// input time
	for(int i=0;i<edge.size();++i){
		int u = edge[i][0], v = edge[i][1];

		g[u].push_back(v);
		g[v].push_back(u);
	}

	// precompute the dp and height table
	dfs(1,0);

	// processing the queries
	int q = query.size();
	for(int i=0;i<q;++i){
		int u = query[i][0];
		int v = query[i][1];

		int lca_of_uv = lca(u,v);
		ans.push_back(lca_of_uv);
	}
	return ans;
}
