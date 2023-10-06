ll kmp(string text, string pattern) // string matching algo
{
    ll tn = text.size(),pn = pattern.size();
    vector<ll> lps(pn);
    ll j=0;
    for(ll i=1;i<pn;i++){
        while(j>0 && pattern[i]!=pattern[j]){
            j = lps[j-1];
        }
        if(pattern[i] == pattern[j]) j++;
        lps[i]=j;
    }
    vector<ll>index; // pattern index is stored in the index vector
    ll i=0; j=0;
    while(i<tn){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==pn) index.push_back(i-pn);
    }
    return (ll)index.size();
}
