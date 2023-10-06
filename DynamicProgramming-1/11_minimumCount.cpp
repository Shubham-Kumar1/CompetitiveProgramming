int minCount(int n)
{
	//Write your code here
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2;i<=n;++i)
    {
        int mini = 1e9;
        for(int j=1;j*j<=i;++j)
        {
            int rem = i - j*j;
            mini = min(mini,dp[rem]);
        }
        dp[i] = 1 + mini;
    }
    return dp[n];
    
}
