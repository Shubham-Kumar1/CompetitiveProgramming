#include <bits/stdc++.h>

vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	vector<vector<int>> start;
	for(int i=0;i<n;++i)
	{
		vector<int> temp;
		temp.push_back(intervals[i][0]);
		temp.push_back(i);
		start.push_back(temp);
	}
	sort(start.begin(),start.end());
	vector<int>A;
	for(int i=0;i<n;++i)
	{
		int key = intervals[i][1];
		int lo = 0,hi = n-1;
		int ans = -1;
		while(lo <= hi)
		{
			int mid = (lo + hi)/2;
			if(start[mid][0] >= key)
			{
				ans = start[mid][1];
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
        }
		A.push_back(ans);
	}
	return A;
}

