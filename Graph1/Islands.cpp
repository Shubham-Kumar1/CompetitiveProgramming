#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int>graph[N];
vector<int>visited(N);

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    visited[node]= 1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : graph[u])
        {
            if(!visited[v])
            {
                visited[v] = 1;
                q.push(v);
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

        for(int i=0;i<n;++i)
        {
            graph[i].clear();
            visited[i] = 0;
        }

        for(int i=0;i<m;++i)
        {
            int u,v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                cnt++;
                bfs(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
