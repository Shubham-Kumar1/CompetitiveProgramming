#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool>seive(n+1,true);
    seive[0] = seive[1] = false;
    for(int i=2;i*i<=n;++i)
        if(seive[i])
            for(int j=i*i;j<=n;j+=i)
                seive[j] = false;
            
    vector<int>primes;
    for(int i=2;i<=n;++i) if(seive[i]) primes.push_back(i);
    
    int cnt=0;
    unordered_set<int> set;
	for(int i = 1 ; i < primes.size() ; ++i) {
		set.insert(primes[i-1] + primes[i]);
	}

	int count = 0;
	for(int i = 2 ; i <= n ; ++i) {
		if(seive[i] && set.count(i-1)) ++count;
	}

	cout << count << '\n';
    return 0;
}
