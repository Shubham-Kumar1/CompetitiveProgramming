#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int>v(n);
        for(int i=0;i<n;++i) cin >> v[i];
        sort(v.begin(),v.end());
        int ans = (int)1e9;
        for(int i=0;i<n-1;++i) ans = min(ans, v[i+1] - v[i]);
        cout << ans << endl;
    }
    return 0;
}
