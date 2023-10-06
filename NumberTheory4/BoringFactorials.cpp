#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll binexpo(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
        res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n, int mod)  // euler's totient --> eulers theorm --> fermat's
{
    return binexpo(n, mod - 2, mod);  // MMI of A is --> A^(mod-2) % mod
}


int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        ll n,p;
        cin >> n >> p;
        
        if(n>=p)
        {
            cout << 0 << endl;
        }else{
           ll res = p-1;
            for(ll i=p-1;i>n;--i)
            {
                res = (res * modInverse(i,p)) % p;
            }
            cout << res << endl;
        }
        
    }
    return 0;
}
