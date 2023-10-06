/*
	Time Complexity : O((N - P)*log(N))
	Space Complexity : O(1)

	Where ‘N’ is the number given and ‘P’ is the given prime number.
*/

long long int power(long long int x, long long int y, long long int p)
{
	long long int res = 1;

	x = x % p;
	while (y > 0)
	{
		// If y is odd, multiply x with result.
		if (y & 1)
		{
			res = (res * x) % p;
		}

		// The y must be even now.
		y = y >> 1;

		x = (x * x) % p;
	}

	return res;
}

long long int modInverse(long long int a, long long int p)
{
	return power(a, p - 2, p);
}

long long int modMultiplication(long long int a, long long int b, long long int m)
{
	a = a % m;
	b = b % m;

	return (((a * b) % m) + m) % m;
}

long long int modDivision(long long int a, long long int b, long long int m)
{
	a = a % m;
	b = b % m;

	return (modMultiplication(a, modInverse(b, m), m) + m) % m;
}

long long int factorialAgain(long long int n, long long int p)
{
	n = modMultiplication(n, 3, p);

	long long int num = (p - 1);


	for (long long int i = n + 1; i < p; i++)
	{
		num = (num * modInverse(i, p)) % p;
	}

	long long int den = 1;
	den = power(6, n / 3, p);

	long long int ans = modDivision(num, den, p);

	return ans;
}
