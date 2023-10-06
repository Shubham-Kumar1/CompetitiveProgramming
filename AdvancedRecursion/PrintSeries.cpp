#include <bits/stdc++.h>
int func1(int n,int k,int aux,vector<int> &ans)
{
    if(aux <= 0)
    {
        return aux;
    }
    ans.push_back(aux);
    func1(n,k,aux-k,ans);
}

void func2(int n,int k,int aux,vector<int> &ans)
{
    if(aux==n)
    {
        ans.push_back(aux);
        return;
    }
    ans.push_back(aux);
    func2(n,k,aux+k,ans);
}

vector<int> printSeries(int n, int k)
{
    // Write your code here
    vector <int> ans;
    int aux=n;
    int new_aux = func1(n,k,aux,ans);
    
    func2(n,k,new_aux,ans);
    return ans;
}

