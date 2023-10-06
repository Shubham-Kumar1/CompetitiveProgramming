#include<bits/stdc++.h>
using namespace std;
bool superprime(int n)
{
    unordered_map<int,int> mp;
    while(n%2==0)
    {
        mp[2]++;
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            mp[i]++;
            n/=i;
        }
    }
    
    if(n>2) mp[n]++;
    
    int k = mp.size();
    if(k==2) return true;
    return false;
    
}

int main(){
    
    // write your code here
    int n;
    cin >> n;
    vector<int>ans;
    for(int i=5;i<=n;++i)
    {
        if(superprime(i)) ans.push_back(i);
    }
    
    // for(auto el : ans)
    //     cout << el << " ";
    cout << ans.size() << endl;
    
    return 0;
}
