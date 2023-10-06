#include <vector>
#include "stack"

vector<int> nextGreaterElement(vector<int> input) {
	int n = input.size();
	vector<int> ans(n);
	stack<int> st;
	for(int i=n-1;i>=0;--i)
	{
		int ele = input[i];
		while(!st.empty() && st.top() <= ele ) st.pop();
		if(st.empty()){
			ans[i] = -1;
		}else{
			ans[i] = st.top();
		}
		st.push(ele);
	}
	return ans;
}

