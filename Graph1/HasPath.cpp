#include<bits/stdc++.h>
using namespace std;

const int N = 10001;
vector<int>graph[10001];

bool bfs(int src,int des)
{
    vector<bool>vis(N,false);
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : graph[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }

    if(vis[src] && vis[des]) return true;
    return false;
}

int main(){

    int t; cin >> t;
    while(t--)
    {
        int v,e; cin >> v >> e;

        for(int i=0;i<v;++i) graph[i].clear();

        for(int i=0;i<e;++i)
        {
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int src,des; cin >> src >> des;

        if(bfs(src,des))
        {
            cout << "true" << endl;
        }else{
            cout << "false" << endl;
        }
    }
    return 0;
}
