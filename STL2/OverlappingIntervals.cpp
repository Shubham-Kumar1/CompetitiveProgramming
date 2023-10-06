#include <bits/stdc++.h>

bool checkOverlappingIntervals(long* start, long* end, int n)
{
    vector<pair<int,int>> vp;
    for(int i=0;i<n;++i) vp.push_back({start[i],end[i]});
    sort(vp.begin(),vp.end());

    for(int i=1;i<n;++i)
    {
        int prev_task_ka_end_time = vp[i-1].second;

        int abhi_ka_start_time = vp[i].first;

        if(abhi_ka_start_time < prev_task_ka_end_time) return true;

    }
    return false;
}

