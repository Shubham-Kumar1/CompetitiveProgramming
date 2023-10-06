#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--)
    {
        int num, kth; cin >> num >> kth;
        int mask = ~(1 << kth);

        int ans = (num & mask);
        cout << ans << endl;

    }
    return 0;
}
