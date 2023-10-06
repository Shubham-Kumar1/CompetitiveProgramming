
bool canPaint(vector<int> &boards, int k, int barrier)
{
    int painter = 1;
    int painted_unit = 0;
    for(int i=0;i<boards.size();++i)
    {
        if(boards[i] > barrier) return false;
        if(painted_unit + boards[i] > barrier)
        {
            painter+=1;
            painted_unit = boards[i];
        }else{
            painted_unit+=boards[i];
        }
    }
    return (painter<=k);
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int maxi = -(int)1e9;
    int sum = 0;

    for(int i=0;i<n;++i)
    {
        maxi = max(maxi,boards[i]);
        sum+=boards[i];
    }
    int lo = maxi,hi=sum;
    int res = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(canPaint(boards,k,mid))
        {
            res = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return res;
}
