#include <unordered_map>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	vector<pair<int,int>> ans;
	unordered_map<int,int> mp;
	for(int i=0;i<n;++i) mp[arr[i]]++;

	for(int i=0;i<n;++i)
	{
		int first = arr[i];
		int next = target - first;
		if(first == next)
		{
			if(mp[first] >= 2){
				ans.push_back({first,first});
				mp[first]-=2;
			}
		}else{
			if(mp[first] > 0 && mp[next]>0){
				ans.push_back({first,next});
				mp[first]-=1;
				mp[next]-=1;
			}
		}
	}
	if(ans.size()==0){
		ans.push_back({-1,-1});
	}
	return ans;
}

