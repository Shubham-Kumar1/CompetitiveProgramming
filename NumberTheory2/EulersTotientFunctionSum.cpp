vector<int> eulerTotientFunction(int n){
  // Write your code here.
  // To store the ans.
  vector<int> ans;

  // Iterate from 1 to 'n'.
  for (int i = 1; i <= n; i++) {

    // If 'i' is a divisor of 'n'.
    if (n % i == 0) {

      // store 'i' in the ans vector.
      ans.push_back(i);
    }
  }

  return ans;
}
