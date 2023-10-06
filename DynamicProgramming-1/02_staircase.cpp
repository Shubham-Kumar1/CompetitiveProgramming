#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = (1e9+7);

signed main()

{
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>dp(n+3,0);
        dp[n]=1;
        dp[n+1]=0;
        dp[n+2]=0;
        for(int i=n-1;i>=0;--i){
            dp[i] = (dp[i+1]+dp[i+2]+dp[i+3]) % mod;
        }
        cout << dp[0]%mod << endl;
    }
    return 0;
}
