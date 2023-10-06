#include <algorithm>

vector<int> searchRange(vector<int> &arr, int x)
{
	vector<int> ans;
	int f = -1, l = -1;
	auto it1 = lower_bound(arr.begin(),arr.end(),x);
	if(it1 == arr.end() || *it1!=x) return {{-1,-1}};
	f = it1 - arr.begin();

	auto it2 = upper_bound(arr.begin(),arr.end(),x);
	l = it2 - arr.begin() - 1;
	return {{f,l}};
}


