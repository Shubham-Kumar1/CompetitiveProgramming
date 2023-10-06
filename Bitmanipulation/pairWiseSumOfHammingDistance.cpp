#define ll long long int
long long int sumOfHammingDistance(int *arr, int n) {

    ll ans = 0;
    for(int i=0;i<=31;++i)
    {
        ll on=0,off=0;
        for(int j=0;j<n;++j)
        {
            if(arr[j] & (1 << i)) on++;
            else off++;
        }
        ans+=(2 * on * off);
    }
    return ans;
}

