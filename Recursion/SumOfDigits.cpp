
int f(int n)
{
    if(n==0) return 0;
    return (n%10) + f(n/10);
}

int sumOfDigits(int n) {
    int ans = f(n);
    return ans;
}



