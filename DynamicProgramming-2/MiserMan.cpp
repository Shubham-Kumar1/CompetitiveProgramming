#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){

    int n = grid.size(), m = grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m) return int(1e9);
    if(i==0) return grid[0][j];
    if(dp[i][j] != -1) return dp[i][j];

    int left_up = grid[i][j] + f(i-1,j-1,grid,dp);
    int up = grid[i][j] + f(i-1,j,grid,dp);
    int right_up = grid[i][j] + f(i-1,j+1,grid,dp);

    return dp[i][j] = min(left_up, min(up,right_up));
}

int main()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> grid[i][j];
        }
    }
    int ans = 1e9;
    for(int j=0;j<m;++j){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int cost = f(n-1,j,grid,dp) ;
        ans = min(ans,cost);
    }
    cout << ans << endl;
    return 0;
}

