#include <bits/stdc++.h>
int f(int ind,int W,vector<int> &weights,vector<int> &values,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(W>=weights[0]) return values[0];
        return 0;
    }
    
    if(dp[ind][W] != -1 ) return dp[ind][W];
    
    int notpick = f(ind-1,W,weights,values,dp);
    
    int pick = 0;
    if(W>=weights[ind])
    {
        pick = values[ind] + f(ind-1,W-weights[ind],weights,values,dp);
    }
    
    return dp[ind][W] = max(pick,notpick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    int ans = f(n-1,w,weights,values,dp);
    return ans;
}
