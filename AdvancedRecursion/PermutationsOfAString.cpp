#include <bits/stdc++.h>
void permutation(string &str,int ind,int len,vector<string> &ans)
{
    if(ind==len)
    {
        ans.push_back(str);
        return;
    }
    
    for(int i=ind;i<len;++i)
    {
        swap(str[i],str[ind]);
        permutation(str,ind+1,len,ans);
        swap(str[i],str[ind]);   
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    int n = str.size();
    vector<string>ans;
    permutation(str,0,n,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
