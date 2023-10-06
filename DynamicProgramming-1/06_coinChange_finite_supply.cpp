const int mod = 1e9+7;
#define ll long long
int ninjaAndCoins(int n, int k, vector<int> &coins)
{
    ll dp[n][k+1];

    for(int i=0;i<n;++i){
        for(int j=0;j<=k;++j){
            if(j==0){ // 0 rupya banane ka tarika hamesa 1 hota he hai ki nahi lenge
                dp[i][j]=1;
                continue;
            }
            if(i==0){ 
                if(j==coins[i]) dp[i][j]=1;
                else dp[i][j]=0;
                continue;
            }
            // not_pick
            dp[i][j] = dp[i-1][j];
            // pick_only if coins[i-1]<=j
            if(j>=coins[i]) dp[i][j] = dp[i-1][j] + dp[i-1][j-coins[i]];
            dp[i][j]%=mod;
        }
    }
    return dp[n-1][k];
}
