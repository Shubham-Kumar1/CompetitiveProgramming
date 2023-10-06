#include<bits/stdc++.h>
#define ll long long
using namespace std;

void f(vector<int> &arr, int ind, vector<vector<int>> &subs,vector<int> &temp)
{
    if(ind == -1)
    {
        subs.push_back(temp);
        return;
    }
    // pick
    temp.push_back(arr[ind]);
    f(arr,ind-1,subs,temp);
    temp.pop_back();

    // not pick
    f(arr,ind-1,subs,temp);
}

int main(){
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n; 
        int k; cin >> k;
        vector<int>v(n);
        for(int i=0;i<n;++i) cin >> v[i];

        vector<vector<int>> subs;
        vector<int> temp;
        f(v,n-1,subs,temp);

        int cnt = 0;
        for(int i=0;i<subs.size();++i)
        {
            ll sum = 0;
            for(int j=0;j<subs[i].size();++j)
            {
                sum+=subs[i][j];
            }
            if(sum==k) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
