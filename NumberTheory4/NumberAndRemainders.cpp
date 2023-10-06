
long long inv(long long a, long long m) {
  long long m0 = m, t, q;
  long long x0 = 0, x1 = 1;

  if (m == 1)
    return 0;

  // Apply extended Euclid Algorithm
  while (a > 1) {
    // q is quotient
    q = a / m;

    t = m;

    // m is remainder now, process same as
    // euclid's algo
    m = a % m, a = t;

    t = x0;

    x0 = x1 - q * x0;

    x1 = t;
  }

  // Make x1 positive
  if (x1 < 0)
    x1 += m0;

  return x1;
}
long long numbersAndRemainders(int k, vector<int> &arr, vector<int> &rem)
{
  // Write your code here.
  // Compute product of all numbers
  long long prod = 1;
  for (int i = 0; i < k; i++)
    prod *= arr[i];

  // Initialize result
  long long result = 0;

  // Apply above formula
  for (int i = 0; i < k; i++) {
    long long pp = prod / arr[i];
    result += rem[i] * inv(pp, arr[i]) * pp;
  }

  return result % prod;

}
