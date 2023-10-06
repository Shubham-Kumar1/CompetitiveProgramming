#include<vector>

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    // Write your code here.
    vector<vector<int>> treeA(n,vector<int>());
    vector<vector<int>> treeB(n, vector<int>());

    // Build the adjacency list for treeA and treeB (BFS check)
    for (auto edge : edgesA) treeA[edge[0]].push_back(edge[1]);
    for (auto edge : edgesB) treeB[edge[0]].push_back(edge[1]);

    for(int i=0;i<n;++i)
    {
        if(treeA[i].size() != treeB[i].size()) return false;

        int j=0,k=treeA[i].size()-1;
        while(k>=0)
        {
            if(treeA[i][j] != treeB[i][k]) return false;
            j++;
            k--;
        }
    }
    return true;
}
