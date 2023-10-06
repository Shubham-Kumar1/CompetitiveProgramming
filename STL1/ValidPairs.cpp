#include <map>
bool CheckSumPairs(int ar[], int n, int k, int m) {

	map<int,int> mp;
	for(int i=0;i<n;++i) mp[ar[i] % k]++;
	for(auto &pr : mp)
	{
		int a = pr.first;
		int b = (m - a + k) % k;
		if(mp[a] != mp[b]) return false;
	}
	return true;
}

