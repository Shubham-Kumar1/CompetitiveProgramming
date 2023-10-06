vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{

    vector<vector<int>> ans;
    // Power Set method
    for(int num=0;num<(1<<n);++num)
    {
        vector<int>v;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(num & (1<<i))
            {
                sum+=arr[i];
                v.push_back(arr[i]);
            }
        }
        if(sum==k) ans.push_back(v);
    }
    return ans;
}
