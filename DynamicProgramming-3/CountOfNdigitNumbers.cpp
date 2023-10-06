#define ll long long
const int MOD = (int)1e9+7;
ll binexpo(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
        res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int countNumbers(int n) {
        if (n > 10)
    {

        // Calculate all numbers upto N-digits.
        ll a = binexpo(10, n,MOD);
        a%=MOD;

        // Calculate all numbers upto (N-1)-digits.
        ll b = binexpo(10, n - 1,MOD);
        b%=MOD;

        ll count = (a - b + MOD) % MOD;

        return count;
    }

    else
    {

        // Total no. of N-digits numbers.
        ll a = ceil(binexpo(10, n,MOD)) - ceil(binexpo(10, n - 1,MOD)) + MOD % MOD;

        ll nonrepeating = 9;

        for (int i = 10 - n + 1; i < 10; i++)
        {

            nonrepeating = (nonrepeating * i ) % MOD;
        }

        ll count = ((a - nonrepeating) + MOD) % MOD;

        return int(count);
    }
}

