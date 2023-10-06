#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DSU {
  vector<ll> parent;
  vector<ll> subtree_size;
  ll N;

public:
  DSU(ll n) {
    N = n;
    parent = vector<ll>(n + 1, 0);
    subtree_size = vector<ll>(n + 1, 1);

    for (int i = 1; i <= n; i++)
      parent[i] = i;
  }

  ll findRoot(ll u) {
    while (u != parent[u]) {
      parent[u] = parent[parent[u]]; // Path compression
      u = parent[u];
    }

    return u;
  }

  bool combine(ll u, ll v) {
    ll ru = findRoot(u); // root of u
    ll rv = findRoot(v); // root of v

    if (ru == rv)
      return false; // no need to join(same group)

    // small to large merging --> (union by rank or size)
    if (subtree_size[ru] > subtree_size[rv]) {
      parent[rv] = ru;
      subtree_size[ru] += subtree_size[rv];
    } else {
      parent[ru] = rv;
      subtree_size[rv] += subtree_size[ru];
    }
    return true;
  }
};

bool cmp(pair<pair<int,int>,int> &pr,pair<pair<int,int>,int> &pr2)
{
    return pr2.second > pr.second;
}


void solve()
{
    ll n,m;
    cin >> n >> m;

    ll res = 0;
    vector<pair<pair<int,int>,int>> vp;
    
    for(int i=0;i<m;++i)
    {
        ll a,b,w; cin >> a >> b >> w;
        vp.push_back({{a,b},w});
    }

    sort(vp.begin(),vp.end(),cmp);

    DSU dsu  = DSU(n);

    for(int i=0;i<vp.size();i++)
    {
        int a = vp[i].first.first;
        int b = vp[i].first.second;
        int cost = vp[i].second;

        if(dsu.combine(a,b))
        {
            res+=cost;
        }
    }
    cout << res << endl;
}

int main(){
    
    // write your code here
    ll t; cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
