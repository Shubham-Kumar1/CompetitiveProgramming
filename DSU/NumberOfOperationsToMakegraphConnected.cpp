#define ll long long
class DSU{
    vector<ll> parent;
    vector<ll> subtree_size;
    ll N;
public:
    DSU(ll n){
        N = n;
        parent = vector<ll>(n+1, 0);
        subtree_size = vector<ll>(n+1, 1);
        for(int i=1; i<=n; i++) parent[i] = i;
    }

    ll findRoot(ll u){
        while(u != parent[u]){
            parent[u] = parent[parent[u]]; //Path compression
            u = parent[u];
        }
        return u;
    }

    bool combine(ll u, ll v){
        ll ru = findRoot(u); // root of u
        ll rv = findRoot(v); // root of v

        if(ru == rv) return false; // no need to join(same group)
        
        // small to large merging --> (union by rank or size)
        if(subtree_size[ru] > subtree_size[rv]){
            parent[rv] = ru;
            subtree_size[ru] += subtree_size[rv];
        } else{
            parent[ru] = rv;
            subtree_size[rv] += subtree_size[ru];
        }
        return true;
    }
};
int makeGraphConnected(int n, vector < pair < int,int > > edges, int m) 
{
	//  n -> no. of nodes
	DSU dsu = DSU(n);
	set<int>st;
	int cycle=0;
	for(int i=0;i<edges.size();++i){
		int u = edges[i].first;
		int v = edges[i].second;
		if(dsu.combine(u,v)==false) cycle++;
	}

	for(int i=1;i<=n;++i){
		int root = dsu.findRoot(i);
		st.insert(root);
	}
	int component = st.size();
	if(cycle < component-1) return -1;
	return component-1;
}
