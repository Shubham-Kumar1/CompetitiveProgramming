// Matrix Exponentiation Concept

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

// sum(R) - sum(L-1);

void prod(long long A[2][2] , long long B[2][2] , int n){
    
    long long temp[2][2] = {{0 , 0} , {0 , 0}};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                temp[i][j] = (temp[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        A[i][j] = temp[i][j];
    }
}

long long fibSum(long long n){
    
    if(n == 0) return 0;
    
    long long T[2][2] = {{1 , 1} , {1 , 0}};
    long long res[2][2] = {{1 , 0} , {0 , 1}};
    
    while(n > 0){
        
        if(n % 2 == 1){
            prod(res , T , 2);
            n--;
        }
        
        n = n / 2;
        prod(T , T , 2);
        
    }
    
    long long sum = (res[0][0] + res[0][1] - 1) % mod;
    
    if(sum < 0) sum = sum + mod;
    
    return sum;
}

int main(){
    
    long long t , n , m;
    
    cin>>t;
    
    while(t--){
        cin>>n>>m;
        
        long long res = (fibSum(m) - fibSum(n-1)) % mod;
        if(res < 0) res = res + mod;
        
        cout<<res<<endl;
    }
    return 0;
}
