const int N = 1e5 + 5;
vector<int> tree[N];
int subtreeXor[N];

void dfs(int s, int p){

    subtreeXor[s]=s;

    for(int v : tree[s]){
        if(v != p){
            dfs(v,s);
            subtreeXor[s]^=subtreeXor[v];
        }
    }
}

vector<int> XORquery(int n, vector<vector<int>> &edges, int q, vector<int> &query) {

    // clearing for the previous output if any
    for(int i=0;i<N;++i){
        tree[i].clear();
        subtreeXor[i]=0;
    }

    // input in the tree
    for(int i=0;i<n-1;++i){
        int u = edges[i][0];
        int v = edges[i][1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0,-1);
    
    vector<int> ans;
    for(int i=0;i<query.size();++i){
        int u = query[i];
        int xorr = subtreeXor[u];
        ans.push_back(xorr);
    }
    return ans;
}
