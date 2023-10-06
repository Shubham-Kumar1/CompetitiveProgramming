#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
vector<bool>seive(N,true);
void createSeive()
{    
    seive[0] = seive[1] = false;
    
    for(ll i=2;i*i<=1e5;++i)
        if(seive[i]==true)
            for(ll j=i*i;j<=1e5;j+=i)
                seive[j] = false;
}

vector<ll> generatePrimes(ll n)
{
    vector <ll> primes;
    for(ll i=1;i<=n;++i)
        if(seive[i]==true) primes.push_back(i);    
    return primes;
}

int main(){
    
    // write your code here
    createSeive();
    
    ll t;
    cin >> t;
    while(t--)
    {
        ll L, R; cin >> L >> R;
        vector<ll>primes = generatePrimes(sqrt(R));
        vector<ll> dummy(R-L+1,1); // segmented seivwe
        for(auto pr : primes)
        {
            ll firstmultiple = (L/pr) * pr;
            if(firstmultiple < L) firstmultiple+=pr;
            for(ll j=max(firstmultiple,pr*pr);j<=R;j+=pr) dummy[j-L]=0;
        }        

        for(ll i=L;i<=R;++i)
            if(dummy[i-L])
            {
                if(i!=1) cout << i << " ";
            }
        cout << endl;
    }
    return 0;
}
