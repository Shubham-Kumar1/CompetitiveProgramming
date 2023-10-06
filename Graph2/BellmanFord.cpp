#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
    int a,b,w;
};

const int N = 1000;
const int inf = 1e9;;
Edge edges[N+1];
int dis[N+1];

void solve(){
    for(int i=1;i< N;++i) dis[i]=inf;
    for(int i=1;i< N;++i){
        edges[i].a=0;
        edges[i].b=0;
        edges[i].w=0;
    }
    int n,m; cin >> n >> m;
    int src, des; cin >> src >> des;
    dis[src]=0;
    for(int i=0;i<m;++i) cin >> edges[i].a >> edges[i].b >> edges[i].w;
    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            if((dis[a] != inf) && (dis[b] > dis[a] + w)){
                dis[b] = dis[a] + w;
            }
        }
    }
    cout << dis[des] << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
