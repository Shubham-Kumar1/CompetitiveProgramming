#include <bits/stdc++.h>
int getMin(int *arr, int n)
{
	//Write your code here
	vector<int>L2R(n,1);
	for(int i=1;i<n;++i)
	{
		if(arr[i] > arr[i-1]) L2R[i] = L2R[i-1] + 1;
	}
	vector<int>R2L(n,1);
	for(int i=n-1;i>=0;--i)
	{
		if(arr[i] > arr[i+1]) R2L[i] = R2L[i+1] + 1;
	}

	int need=0;
	for(int i=0;i<n;++i)
	{
		need+=(max(L2R[i],R2L[i]));
	}
	return need;
}
