string reverseString(string &s){
	int n = s.size();
	string ans = "";
	int j;

	for(int i=n-1;i>=0;--i)
	{
		if(s[i]==' ') continue;
		
		j = i;
		while(j>=0 && s[j]!=' ')j--;

		ans+=s.substr(j+1,i-j);
		ans+=' ';
		i=j;
	}
	return ans;
}
