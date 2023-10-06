#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int ans =0 ;
    vector<int>dp(n,1);
    for(int i=0;i<n;++i){
        int pos = lower_bound(dp.begin(),dp.begin()+ans,arr[i]) - dp.begin();
        dp[pos]=arr[i];
        if(pos==ans) ans++;
    }
    return ans;
}

