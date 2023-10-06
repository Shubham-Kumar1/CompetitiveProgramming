

#define ll long long

bool f(ll n, ll r, ll k, ll c, ll mid) // --> mid no. of pens recycle ho skta hai ki nahi
{
	ll chahie_rupya = mid * c;
	ll available = r + ((n - mid) *k);

	if(available>=chahie_rupya) return true;
	return false;
}

int recyclePens(int n, int r, int k, int c ){

	ll lo=0,hi=n;
	int ans = 0;
	while(lo<=hi)
	{
		ll mid = (lo + hi) / 2;
		if(f(n,r,k,c,mid))
		{
			ans = mid;
			lo = mid + 1;
		}else{
			hi = mid -1;
		}
	}
	return ans;
	
}
