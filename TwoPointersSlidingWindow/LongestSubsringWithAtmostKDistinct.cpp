#include <map>
int getLengthofLongestSubstring(int k, string s)
{
   int n = s.size();
   int i=0,j=0;
   int ans = 0;
   map<char,int> mp;
   while(j<n){
      mp[s[j]]++;
      while(mp.size() > k){
         mp[s[i]]--;
         if(mp[s[i]]==0) mp.erase(s[i]);
         i++;
      }
      ans = max(ans,j-i+1);
      j++;
   }
   return ans;
}

