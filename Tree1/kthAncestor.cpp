
vector<vector<int>> graph;
vector<int> visited;

int ans = -1;
int k;

bool helper(int node,int target)
{
    if(node==target)
    {
        k--;
        return true;
    }
    visited[node] = 1;

    for(int i=0;i<graph[node].size();++i)
    {
        int adj = graph[node][i];
        if(visited[adj] == false)
        {
            if(helper(adj, target))
            {
                if(k==0) ans = node;

                k--;
                return true;
            }
        }
    }
    return false;
}

void init(int n, int K)
{
    graph.resize(n);
    visited.resize(n);
    k = K;
    ans = -1;
    for(int i=0;i<n;++i)
    {
        graph[i].clear();
        visited[i] = 0;
    }
}
int kthAncestor(int n, vector<int>  &parent, int node, int K)
{

    init(n,K);

    // Create tree with the given parent (edge between i and parent[i])
    for(int i=1;i<parent.size();++i)
    {
        // parent of i is in parent[i];
        int u = parent[i];
        graph[u].push_back(i);
    }
    helper(0,node);
    return ans;
}
