
int f(int input[],int ind)
{
  if(ind==-1) return 0;
  return input[ind] + f(input,ind-1) ;
}

int sum(int input[], int n) {
  int ans = f(input,n-1);
  return ans;
}

