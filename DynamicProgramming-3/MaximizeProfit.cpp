
const int N = 1e5+5;
vector<int> g[N];
int costs[N];
long long dp1[N], dp2[N];
void dfs(int s,int p)
{
    dp1[s] = costs[s];
    dp2[s] = 0;

    for(int v : g[s])
    {
        if(v != p)
        {
            dfs(v,s);
            dp1[s]+=dp2[v];
            dp2[s]+= max(dp1[v],dp2[v]);
        }
    }
}

long long int maximizeProfit(int n, vector<int> c, vector<vector<int>> edges)
{   
    for(int i=0;i<=n;++i)
    {
        g[i].clear();
        costs[i] = 0;
        dp1[i] = dp2[i] = 0;
    }

    for(int i=1;i<=n;++i) costs[i] = c[i-1];
    for (auto& i : edges)
    {
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }

    dfs(1,0);
    return max(dp1[1],dp2[1]);

}
