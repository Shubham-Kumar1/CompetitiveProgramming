#include <bits/stdc++.h>
int f(int *arr,int ind,vector<int> &dp)
{
	if(ind==0) return arr[ind];

	if(ind < 0) return 0;

	if(dp[ind] != -1) return dp[ind];
	int notpick = 0 + f(arr,ind-1,dp);

	int pick = arr[ind] + f(arr,ind-2,dp);

	return dp[ind] = max(pick,notpick);

}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	vector<int>dp(n+1,-1);
	int ans = f(arr,n-1,dp);
	return ans;
}
