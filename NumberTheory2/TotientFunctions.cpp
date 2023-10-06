#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll phi(ll n)
{
    ll ans = n;
    unordered_map<ll,ll> mp;
    for(ll i=2;i*i<=n;++i)
    {
        while(n%i==0)
        {
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
    
    for(auto pr : mp)
    {
        ans = ans * (pr.first-1)/pr.first;
    }
    return ans;
}


int main(){
    
    // write your code here
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll cnt = phi(n);
        cout << cnt << endl;
    }
    return 0;
}
