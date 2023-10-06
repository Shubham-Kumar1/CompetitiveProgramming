#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return ((a.first)*(b.second)) > ((a.second) * (b.first));
}

int main(){

    int n,W; cin >> n >> W;
    vector<pair<int,int>> vp(n); // value wt
    for(int i=0;i<n;++i)
    {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(),vp.end(),cmp);

    double ans = 0;
    double initial_wt = 0;

    for(int i=0;i<n;++i)
    {
        if(initial_wt + vp[i].second <= W)
        {
            initial_wt+=vp[i].second;
            ans+=(vp[i].first);
        }else{
            double rem_wt = W - initial_wt;
            double valbywt = ((double)vp[i].first)/((double)vp[i].second);
            ans+=(rem_wt * valbywt);
            break;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
