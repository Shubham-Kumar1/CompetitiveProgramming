#include<bits/stdc++.h>
using namespace std;

vector <int> arr(1e6+1,0);
void cubic(vector<int> &arr){
    
    arr[1]=1;
    for(int i=2;i<=100;i++){
        int cube=i*i*i;
        for(int j=1;cube*j<=(1e6);j++){
            arr[cube*j]=-1;   
        }
    }

    int curr=1;
    for(int i=1;i<=(1e6);i++){
        if(arr[i]!=-1){
            arr[i]=curr;
            curr++;
        }
    }
}

int main(){
    
    int t;
    cin >> t;
    
    cubic(arr);
    
    while(t--){
        int n;
        cin >> n;
        
        if(arr[n]!=-1){
            cout<<arr[n]<<endl;
        }
        else{
            cout<<"Not Cube Free"<<endl;
        }
    }
}
