int requiredCandies(vector < int > &students) {
    int n = students.size();
    vector<int> milega(n,1);
    for(int i=0;i<n-1;++i)
    {
        if(students[i+1] > students[i]){
            milega[i+1] = milega[i] + 1;
        }
    }
    
    for(int i=n-2;i>=0;--i)
    {
        if(students[i] > students[i+1]  && milega[i] <= milega[i+1])
        {
            milega[i]=milega[i+1] +1;
        }
    }
    int ans = 0;
    for(auto &c : milega) ans+=c;
    return ans;
}
