
bool canPlace(vector<int> &stalls, int n, int no_of_cows, int dist)
{
    int cnt = 1;
    int prev = stalls[0];

    for(int i=1;i<n;++i){
        if(stalls[i] - prev >= dist)
        {
            cnt++;
            prev = stalls[i];
        }
        if(cnt==no_of_cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());

    int lo=1,hi = stalls.back() - stalls.front();
    int ans = lo;

    while(lo<=hi)
    {
        int mid = (lo + hi) / 2;
        if(canPlace(stalls,n,k,mid))
        {
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return ans;
    
}
