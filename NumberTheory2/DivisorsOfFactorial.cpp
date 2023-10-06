#include "bits/stdc++.h"
#define ll long long
using namespace std;

const int mod = int(1e9+7);

/*----------- seive --------------*/
const ll n = 50001;
vector <bool> seive(n+5,true);
vector <ll> primes;
void createSeive()
{
    seive[0] = seive[1] = false;
    for(ll i=2;i*i<=n;++i)
        if(seive[i])
            for(ll j=i*i;j<=n;j+=i)
                seive[j] = false;
}
/*--------------------------------*/

ll func(ll n, ll ele)
{
    ll cnt=0;
    for(int i=1;;++i)
    {
        ll divide = pow(ele,i);
        if(divide<=n)
        {
            cnt+=(n/divide);
        }
        else if (divide>n)
        {
            break;
        }
    }
    // cout << "for " << ele << " count comes to be " << cnt << endl; 
    
    return cnt;
}

void solve()
{
    ll n;
    cin >> n;
    
    // find all the primes till n;
    vector<ll>primes;
    for(ll i=2;i<=n;++i) if(seive[i]) primes.push_back(i);
        
    // cout << "primes till " << n << endl;
    // for(auto pr : primes) cout << pr << " ";
    // cout << endl;

        
    vector <ll> st;

    for(ll i=0;i<primes.size();++i)
    {
        ll cnt = func(n,primes[i]);
        st.push_back(cnt);
    }
    
    ll res = 1;
    for(ll it : st)
    {
        res = ((res)%mod * (it + 1)%mod) % mod;
    }
    cout << res << endl;
}


int main()
{
    createSeive();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
