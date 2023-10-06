#include <bits/stdc++.h>
#define ll long long

vector<int> calZarray(string s){
    int n = s.size();
    vector<int>z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int zAlgorithm(string text, string pattern, int n, int m)
{   
    int tn = text.size();
    int pn = pattern.size();
    
    string newString=pattern;
    newString+=(char)('#');
    newString+=text;

    int newLen = newString.size();
    vector<int>index;
    vector<int>Zarray = calZarray(newString);
    
    for(int i=0;i<newLen;i++){
        if(Zarray[i] == pn) index.push_back(i-pn-1);
    }
	return int(index.size());
}
