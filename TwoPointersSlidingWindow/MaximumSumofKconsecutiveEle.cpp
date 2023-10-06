
//Max Sum of K Consecutive Elements
//Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.
//Please note that a subarray is the sequence of consecutive elements of the array.

#include <bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();
	priority_queue<int, vector<int> , greater<int>> pq;
	for(int i=0;i<n;++i){
		int sum = 0;
		for(int j=i;j<n;++j){
			sum+=arr[j];
			pq.push(sum);
			if(pq.size() > k) pq.pop();
		}
	}
	return pq.top();
}
