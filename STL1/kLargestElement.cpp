// Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.

#include <queue>
int kthLargest(int* arr, int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;++i)
    {
        pq.push(arr[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}

