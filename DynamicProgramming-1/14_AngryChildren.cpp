#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll n,k; cin >> n >> k;
    vector<ll>v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    sort(v.begin(),v.end());
    vector<ll>pre(n+1,0);
    for(int i=1;i<=n;++i)
    {
        pre[i] = pre[i-1] + v[i-1];
    }
    ll current=0;
    for(int i=0;i<k;++i)
    {
        current+=(i*v[i] - pre[i]);
    }
    ll ans = current;
    for(int i=k;i<n;++i)
    {
        current = current - 2 * (pre[i] - pre[i-k+1]) + (k-1)*(v[i] + v[i-k]);
        ans = min(ans,current);
    }
    cout << ans << endl;
}
int main(){
    
    // write your code here
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    
    return 0;
}
