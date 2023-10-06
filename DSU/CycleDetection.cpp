class DSU{
    private:
    vector<int>parent;
    vector<int>subtreeSize;
    int N;

    public:
      DSU(int n) {
        N = n;
        parent = vector<int>(n + 1, 0);
        subtreeSize = vector<int> (n+1,1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
      }

      // finding the candiadte key that belong to the SET
        int findroot(int u){
            while(u != parent[u]){
                parent[u] = parent[parent[u]];
                u = parent[u];
            }
            return u;
        }
        // combine the two nodes if they dont belong to the same set
        bool combine(int u, int v){
            int ru = findroot(u);
            int rv = findroot(v);
            if(ru==rv) return false;

            if(subtreeSize[ru] > subtreeSize[rv]){
                parent[rv] = ru;
                subtreeSize[ru]+=rv;
            }else{
                parent[ru]=rv;
                subtreeSize[rv]+=ru;
            }
            return true;
        }
};

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    DSU d = DSU(n);
    for(int i=0;i<edges.size();++i){
        int x = edges[i][0];
        int y = edges[i][1];
        if(d.combine(x,y) == false){
            return "Yes";
        }
    }
    return "No";
}

