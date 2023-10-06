
// Calculation of nCr
// You are given two integers 'n' and 'r' and a prime number 'p'. Your task is to find (nCr) % p where nCr can be calculated as n! / (r! * (n - r)!).


#define ll long long
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

vector<ll>fact;
void factorial(ll n,ll mod)
{
    fact.resize(n+1);
    fact[0]=1;
    for(int i=1;i<=n;++i) fact[i] = (fact[i-1]*i)%mod;
}

ll nCrModPFermat(ll n, ll r, ll mod)  // nCr % mod calculation
{
    fact.resize(n+1);
    if (n < r) return 0;  // If n<r, then nCr should return 0
    if (r == 0) return 1;  // Base case
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    return (fact[n] * modInverse(fact[r], mod) % mod* modInverse(fact[n - r], mod) % mod)% mod;
}

unsigned long long  fermatLittle(int n, int r, int p)
{
    // Write your code here.
    
    return nCrModPFermat(n,r,p);
    
    
}
