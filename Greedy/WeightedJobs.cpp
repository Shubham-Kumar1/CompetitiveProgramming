#include<bits/stdc++.h>
using namespace std;

struct Job{
    int start,end,profit;
};

bool cmp(Job a, Job b)
{
    return a.end < b.end;
}
int binarySearch(Job arr[], int ind)
{
    int lo=0,hi=ind-1;
    while(lo<=hi)
    {
        int mid = (lo + hi)/2;
        if(arr[mid].end <= arr[ind].start)
        {
            if(arr[mid + 1].end <= arr[ind].start){
                lo = mid + 1;
            }else{
                return mid;
            }
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}
int main(){

    int n; cin >> n;
    Job arr[n];
    for(int i=0;i<n;++i){
        cin >> arr[i].start >> arr[i].end >> arr[i].profit;
    }
    sort(arr,arr+n,cmp);
    int dp[n] = {0};
    dp[0] = arr[0].profit;

    for(int i=1;i<n;++i)
    {
        int including = arr[i].profit;
        int prev = binarySearch(arr,i);
        if(prev != -1)
        {
            including+=dp[prev];
        }
        dp[i] = max(dp[i-1],including);
    }
    cout << dp[n-1] << endl;
    return 0;
}
