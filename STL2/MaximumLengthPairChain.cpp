#include <bits/stdc++.h>

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}
int maxLengthChain(vector<pair<int, int>> &p, int n) {

    sort(p.begin(),p.end(),cmp);

    int i = 0, j=1;
    int cnt = 1;

    while(j < n)
    {
        if(p[i].second < p[j].first){
            cnt++;
            i = j;
        }
        j++;
    }
    return cnt;
}
