vector<int> stringQueries(string s, int q, vector<vector<int>> query) {
    vector<int> ans;

    int n = s.size();
    for(int i=0;i<q;++i){
        int tp = query[i][0];
        int idx = query[i][1];
        if(tp==1){
            int cnt=1;
            int r=0;
            for(int j=idx;j<n-1;++j){
                if(s[j]==s[j+1]){
                    r++;
                }
                else break;
            }
            int l=0;
            for(int j=idx;j>0;--j){
                if(s[j]==s[j-1]) l++;
                else break;
            }
            cnt+=(l + r);
            if(s[idx]=='#') cnt=-1;
            ans.push_back(cnt);
        }else{
            s[idx]='#';
        }
    }
    return ans;
}

