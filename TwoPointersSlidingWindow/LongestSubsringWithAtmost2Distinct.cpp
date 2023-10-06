#include <map>
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int i=0,j=0;
    int ans = 0;
    map<char,int> mp;
    while(j < n && i<=j){
        mp[s[j]]++;
        while(mp.size() > 2){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

