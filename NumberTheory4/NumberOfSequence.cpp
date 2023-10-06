/*
    Time Complexity : O(N * Log(N))
    Space Complexity : O(N)

    Where 'N' is the size of the array.
*/

int check(int x, vector<int>& v)
{
    int cur = -1;
    int n = v.size();
    for (int i = x; i < n; i += x)
    {
        if (v[i] != -1)
        {
            if (cur == -1)
            {
                cur = v[i] % x;
            }
            else
            {
                if (v[i] % x != cur)
                {
                    return 0;
                }
            }
        }
    }

    if (cur == -1)
    {
        return x;
    }
    else {
        return 1;
    }
}

int solve(vector<int> arr)
{
    int n = arr.size();

    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        v[i] = arr[i - 1];
    }

    if (v[1] != 0 && v[1] != -1)
    {
        return 0;
    }

    vector<long long int> isprime;
    isprime.resize(n + 1, 1);

    int sqrtn = min((int)sqrt(n) + 1, n);

    vector<long long int> primes;

    for (int i = 2; i <= sqrtn; i++)
    {
        long long int cur = i * 2;
        if (!isprime[i])
        {
            continue;
        }

        while (cur <= n)
        {
            isprime[cur] = 0;
            cur += i;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }

    long long int res = 1;

    for (int i = 0; i < primes.size(); i++)
    {
        long long int cur = primes[i];
        while (cur <= n)
        {
            int temp = check(cur, v);
            if (temp == cur) {
                res *= primes[i];
            }
            else {
                res *= temp ;
            }
            res %= 1000000007;
            cur *= primes[i];
        }
    }
    return res;
}
