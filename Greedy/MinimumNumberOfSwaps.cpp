int minSwap (int n, int m, int k, string &s, vector<char> &ch)
{
    // Write your code here.
    vector<int>flag(26);
    for(int i=0;i<m;i++) flag[ch[i]-'a']=1;
    
    int freq[k][26];
    for(int i=0;i<k;i++)
        for(int j=0;j<26;j++)
            freq[i][j]=0;
    
    for(int i=0;i<n;i++) freq[i%k][s[i]-'a']++;
    
    int total=0;
    for(int i=0;i<k;i++){
        int maxi=0;
        int sum=0;
        for(int j=0;j<26;j++){
            sum+=freq[i][j];
            if(freq[i][j]>maxi && flag[j]==1) maxi = freq[i][j];
        }
        total+=(sum-maxi);
    }
    return total;


}
