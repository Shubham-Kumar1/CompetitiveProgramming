#include<bits/stdc++.h>
#define int long long
const int N = (int)1e5+7;
using namespace std;
void solve()
{
    int n; cin >> n;
    vector<int>freq(N,0);
    int maxi = 0;
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        freq[x]++;
        maxi = max(maxi,x);
    }
    
    vector<int>ans(N,0);
    ans[0] = 0;
    ans[1] = freq[1];
    for (int i = 2; i < N ; ++i)
    {
        ans[i] = max(ans[i-1],ans[i-2]+freq[i]*i);
    }
    cout << ans[maxi] << endl;
    
}

signed main(){

    int t=1; 
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
