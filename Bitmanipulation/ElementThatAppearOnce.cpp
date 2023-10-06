
//You are given an arbitrary array ‘arr’ consisting of N non-negative integers, where every element appears thrice except one. You// need to find the element that appears only once.

int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.
    int res=0;
    vector<int>f(32,0);
    for(int i=0;i<31;++i)
        for(int j=0;j<arr.size();++j)
            if(arr[j] & (1 << i)) f[i]++;
    
    for(int i=0;i<31;++i)
        if(f[i]%3==1) res+=(1 << i);
    return res;
}
