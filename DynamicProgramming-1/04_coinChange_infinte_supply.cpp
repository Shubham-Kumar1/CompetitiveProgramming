#include <bits/stdc++.h>
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

    int n = numDenominations;
    int v = value;

    int dp[n+1][v+1];

    for(int j=0;j<=v;++j) dp[0][j]=0;
    for(int i=0;i<=n;++i) dp[i][0]=1;

    for(int i=1;i<=n;++i){
      for(int j=1;j<=v;++j){
        if(denominations[i-1] > j){ // nahi le skte hai
          dp[i][j] = dp[i-1][j];
        }else{
          dp[i][j] = dp[i-1][j] + dp[i][j-denominations[i-1]];
        }
      }
    }
    return dp[n][v];
}

