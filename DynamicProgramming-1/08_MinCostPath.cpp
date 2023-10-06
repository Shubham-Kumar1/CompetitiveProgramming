int min(int a, int b){
    if(a > b) return b;
    return a;
}
// n - number of rows
/// m - number of columns
int minCostPath(int **input, int n, int m) {

    int dp[n][m];

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){

            if(i==0 && j==0) dp[0][0] = input[0][0];
            else if(i==0) dp[i][j] = dp[i][j-1] + input[i][j];
            else if(j==0) dp[i][j] = dp[i-1][j] + input[i][j];
            else{
                dp[i][j] = 1e9;
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + input[i][j];
            }
        }
    }
    return dp[n-1][m-1];
}

