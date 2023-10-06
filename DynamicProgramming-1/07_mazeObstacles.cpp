const int mod = 1e9+7;
#define ll long long
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i==0 && j==0) dp[i][j]=1;
            else{
                dp[i][j] = 0;
                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
            }

            if(mat[i][j]==-1) dp[i][j]=0;
            dp[i][j]%=mod;
        }
    }
    return dp[n-1][m-1];
}
