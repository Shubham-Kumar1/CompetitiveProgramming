#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll k;

ll n;

string a,b;

 

ll dp[30][2][300][101];

 

bool isPrime(ll x)

{

   if(x<=1){

       return false;

   }

   for(ll i=2;i*i<=x;i++){

       if(x%i==0)return false;

   }

   return true;

}

 

ll fun(ll ind, ll strict, ll sum, ll rem)

{

   if(ind==n){

       

       if(isPrime(sum)&&rem%k==0){

//             cout<<"sum "<<sum<<" rem "<<rem<<endl;

           return 1;

       }

       return 0;

   }

   ll ans = 0;

   if(dp[ind][strict][sum][rem] != -1){

       return dp[ind][strict][sum][rem];

   }

   if(strict==0){

       for(ll i=0;i<10;i++)

       {

           ans += fun(ind+1,0,sum+i,(rem*10+i)%k);

       }

       return dp[ind][strict][sum][rem] = ans;

   }

   else{

       ll i;

       for(i=0;i<a[ind]-'0';i++)

       {

           ans += fun(ind+1,0,sum+i,(rem*10+i)%k);

       }

       ans += fun(ind+1,1,sum+i,(rem*10+i)%k);

       return dp[ind][strict][sum][rem] = ans;

   }

}

 

 

 

ll countMagicalNumbers(ll A, ll B, ll K)

{

   // Write your code here.

   k = K;

   A--;

   a = to_string(A);

   n = a.size();

   memset(dp,-1,sizeof(dp));

   ll ans1 = fun(0,1,0,0);

   

   memset(dp,-1,sizeof(dp));

   a = to_string(B);

   n = a.size();

   ll ans2 = fun(0,1,0,0);

//     cout<<ans2<<" "<<ans1<<endl;

   return ans2-ans1;

   

}
