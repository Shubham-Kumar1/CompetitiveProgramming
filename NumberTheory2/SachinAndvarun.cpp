#include<bits/stdc++.h>
using namespace std;
long long extendedGCD(long long a , long long b , long long& x , long long& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long x1 , y1, g;
    g = extendedGCD(b , a%b , x1 , y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int main(){
    int t , a , b , d;   // ax + by = d (such that x>=0 && y>=0)
    cin>>t;
    while(t--){
        cin>>a>>b>>d;
        long long x , y , g;
        g = extendedGCD(a , b , x , y);
        if(d % g == 0){
            x = x * (d / g);
            y = y * (d / g);
            long long L = ceil(-1.0 * x / (b/g));
            long long R = floor(1.0 * y / (a/g));
            if(L > R) cout<<0<<endl;
            else      cout<<R - L + 1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
