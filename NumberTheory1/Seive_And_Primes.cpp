#define ll long long
vector<int> primeNumbersTillN(int N) 
{ 
 	// Write your code here
	 vector<int>primes;
	vector<int>seive(N+1,1);
	seive[0]=seive[1]=0;

	for(ll i=2;i*i<=N;++i){
		if(seive[i]){
			for(ll j=i*i;j<=N;j+=i){
				seive[j]=0;
			}
		}
	}
	for(ll i=2;i<=N;++i){
		if(seive[i]) primes.push_back(i);
	}
	return primes;
}
