#include <bits/stdc++.h>
void cSum(vector<int> &A,int ind, int n, int target, vector<int> &temp, vector<vector<int>> &ans)
{
    //base
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    
    if(ind >= n || (target - A[ind] < 0)) return;
    
    //pick
    temp.push_back(A[ind]);
    cSum(A,ind,n,target-A[ind],temp,ans);
    
    //not pick
    temp.pop_back();
    cSum(A,ind+1,n,target,temp,ans);
}

vector<vector<int>> combSum(vector<int>& ARR, int B)
{
	// Write your code here
	// Return a vector of sorted vectors/combinations
    vector<vector<int>> ans;
    vector <int> A = ARR, temp;
    sort(A.begin(),A.end());
    
    cSum(A,0,A.size(),B,temp,ans);
    return ans;
}

