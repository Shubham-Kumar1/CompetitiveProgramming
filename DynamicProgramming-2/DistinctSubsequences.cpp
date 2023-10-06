#include <bits/stdc++.h>
const int mod = int(1e9+7);
#define ll long long
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        vector<ll>dp(n+1);
        dp[0]=1;
        unordered_map<char,int> mp;

        for(int i=1;i<=n;++i){
            char ch = s[i-1];
            dp[i] = (2 * dp[i-1]) % mod; // yeh wla to hmesa hota hai

            if(mp.find(ch)!= mp.end()){
                int j = mp[ch];
                dp[i] = (dp[i] - dp[j-1] + mod) % mod;
            }
            mp[ch]=i;
        }
        cout << dp[n] << endl;
    }
}

