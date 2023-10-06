
// observation hai ek baar starting 15 n ke liye print krke dekhlo pattern dikh jayega

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        if(n%4==0) cout << n << endl;
        else if(n%4==1) cout << 1 << endl;
        else if(n%4==2) cout << n+1 << endl;
        else if(n%4==3) cout << 0 << endl;
    }
    return 0;
}
