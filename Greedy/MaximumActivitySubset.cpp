#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}

int main(){

    int n; cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;++i) cin >> vp[i].first >> vp[i].second;

    sort(vp.begin(),vp.end(),cmp);

    int prev_end = vp[0].second;
    int ans = 1;

    for(int i=1;i<n;++i)
    {
        if(vp[i].first >= prev_end)
        {
            ans++;
            prev_end = vp[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
