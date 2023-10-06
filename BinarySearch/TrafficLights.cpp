#include <bits/stdc++.h>

vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	vector<int> A;
	set<int>positions;
	multiset<int> lengths;
	positions.insert(0);
	positions.insert(x);
	lengths.insert(x);

	for(int i=0;i<n;++i)
	{
		int added = pos[i];
		positions.insert(added);
		auto itr = positions.find(added);
		int prev_val = *prev(itr);
		int next_val = *next(itr);
		lengths.erase(lengths.find(next_val - prev_val));
		lengths.insert(added-prev_val);
		lengths.insert(next_val-added);

		int ans = *lengths.rbegin();
		A.push_back(ans);
	}
	return A;
}
