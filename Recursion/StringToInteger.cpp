#include <bits/stdc++.h>
int f(char input[],int ind)
{
    if(ind == -1) return 0;
    return (input[ind] - '0') + 10 * f(input,ind - 1);
}
int stringToNumber(char input[]) {

    int n = strlen(input);
    int ans = f(input,n-1);
    return ans;
}
