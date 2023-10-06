#include <bits/stdc++.h>
bool cmp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
{
    int l1 = a.second.first;
    int t1 = a.second.second;
    int l2 = b.second.first;
    int t2 = b.second.second;

    if(l1*t2 == l2*t1) return a.first < b.first; // for indx wise sorting
    return (l1*t2) > (l2 * t1);
}

vector<int> minLoss(int n, vector<int> &t, vector<int> &l) {
    vector<int>ans;
    vector<pair<int,pair<int,int>>> vp;
    for(int i=0;i<n;++i)
    {
        vp.push_back({i+1,{l[i],t[i]}});
    }
    sort(vp.begin(),vp.end(),cmp);
    for(int i=0;i<n;++i) ans.push_back(vp[i].first);
    return ans;
}
