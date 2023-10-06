#define ll long long
const int mod = int(1e9 + 7);

ll binexpo(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

ll blackbox(string str) {
  ll pr = 1;
  ll hash = 0;

  for (auto it : str) {
    hash = (hash + ((it - 'A' + 1) * pr) % mod) % mod;
    pr = (pr * 31) % mod;
  }
  return hash;
}

vector<int> stringMatch(string &s, string &p) {
  // Write your code here
  vector<int> ans;
  int plen = p.length();
  int slen = s.length();

  ll phash = blackbox(p);
  string temp = s.substr(0, plen);
  ll shash = blackbox(temp);
  int cnt = 0;
  if (phash == shash) {
    ans.push_back(0);
  }
  ll prL = 1;
  ll prR = binexpo(31, plen, mod);

  for (int i = plen; i < slen; ++i) {
    shash = (shash - ((s[i - plen] - 'A' + 1) * prL) % mod + mod) % mod;
    shash = (shash + ((s[i] - 'A' + 1) * prR) % mod) % mod;
    phash = (phash * 31) % mod;

    if (shash == phash) {
      ans.push_back(i - plen + 1);
    }
    prL = (prL * 31) % mod;
    prR = (prR * 31) % mod;
  }
  return ans;
}

