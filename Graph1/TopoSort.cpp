#include<bits/stdc++.h>

using namespace std;

const int N = 100000;
vector<int> ar[N+1];
int inDegree[N+1];

void topSort(int n){

	queue<int> q;

	for(int i=1;i<=n;i++)
		if(inDegree[i] == 0) q.push(i);

	while(q.empty() == false){
		int node = q.front();
		q.pop();
		cout<<node<<" ";

		//node -> v
		for(int v : ar[node]){
			inDegree[v]--;

			if(inDegree[v] == 0) q.push(v);
		}

	}

}

int main(){
	int n , m , a , b;

	cin>>n>>m;

	for(int i=1;i<=n;i++) inDegree[i] = 0;

	while(m--){
		cin>>a>>b;
		ar[a].push_back(b);
		inDegree[b]++;
	}

	topSort(n);
}
