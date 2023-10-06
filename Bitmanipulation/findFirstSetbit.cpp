#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    if(n & 1)
    {
        cout << 1 << endl;
        return;
    }

    for(int i=0;i<=31;++i)
    {
        if(n & (1 << i))
        {
            cout << (1 << i) << endl;
            return;
        }
    }
}

int main(){

    int t; cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
