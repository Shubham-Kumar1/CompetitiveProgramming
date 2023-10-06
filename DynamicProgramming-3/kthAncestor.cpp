int kthAncestor(int n, vector<int> & parent, int node, int k)
{
    // Write your code here.

    vector < int > v;
    v.push_back(node);

    while(1){
     
      if(parent[node] == -1)break;

      v.push_back(parent[node]);
      node = parent[node];


    }
    if(k >= v.size())return -1;
    return v[k];


}
