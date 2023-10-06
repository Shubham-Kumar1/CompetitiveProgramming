int matrixChainMultiplication(int* arr, int n) {
    int dp[n][n];
    // f(i,j) = min(f(i,k) + f(k+1,j)) + a[i]*a[k+1]*a[j+1];

    for(int i=0;i<n;++i) dp[i][i] = 0;

    for(int i=n-2;i>=0;--i){
        for(int j=i+1;j<n;++j){
            dp[i][j]=1e9;
            for(int k=i;k<j;++k){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j+ arr[i]*arr[k+1]*arr[j+1]]);
            }
        }
    }
    return dp[0][n-1];
}
