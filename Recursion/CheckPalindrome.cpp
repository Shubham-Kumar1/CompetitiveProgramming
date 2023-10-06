#include <cstring> // ----> for strlen
bool f(char input[], int i, int j)
{
    if(i >= j) return true;
    if(input[i] != input[j]) return false;
    return f(input,i+1,j-1);
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int n = strlen(input);
    int i=0;
    int j = n-1;
    bool flag = f(input,i,j);
    return flag;
}

