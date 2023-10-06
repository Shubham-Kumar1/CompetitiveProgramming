string a;
int n,k;

int dp[30][2][10000+5][2];

int fun(int ind,int strict, int pdt, int num, int start)

{

   if(pdt>k){

       return 0;

   }

   if(ind==n){

       if(start==0)return 0;

//         if(pdt==k)

//             cout<<"num "<<num<<endl;

       return (pdt==k);

   }

   if(dp[ind][strict][pdt][start]!=-1){

       return dp[ind][strict][pdt][start];

   }

   if(strict==0){

       int ans = 0;

       if(start==0){

           ans+=fun(ind+1,0,1,0,0);

           for(int i=1;i<10;i++){

               ans+=fun(ind+1,0,i,num*10+i,1);

           }

           return dp[ind][strict][pdt][start] = ans;

       }

       for(int i=0;i<10;i++){

           ans+=fun(ind+1,0,pdt*i,num*10+i,1);

       }

       return dp[ind][strict][pdt][start] = ans;

   }

   else{

       int ans = 0;

       if(start==0){

           ans+=fun(ind+1,0,1,0,0);

       }else{

           if(a[ind]=='0'){

               ans+=fun(ind+1,1,pdt*0,num*10+0,1);

               return dp[ind][strict][pdt][start] = ans;

           }

           ans+=fun(ind+1,0,pdt*0,num*10+0,1);  

       }

       int i=1;

       for(;i<a[ind]-'0';i++){

           ans+=fun(ind+1,0,pdt*i,num*10+i,1);

       }

       ans+=fun(ind+1,1,pdt*i,num*10+i,1);

       return dp[ind][strict][pdt][start] = ans;

   }

}

 

int f(int x)

{

   if(x==0)return 0;

   a = to_string(x);

   n = a.size();

   memset(dp,-1,sizeof(dp));

   return fun(0,1,1,0,0);

}


int numsWithProductK(int l, int r, int K) {

// Write your code here.

   k = K;

   return f(r)-f(l-1);

}
