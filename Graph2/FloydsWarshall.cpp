#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> graph(n+1, vector<int>(n+1, INF));

        // Initialize the distance matrix with edge weights
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c); // Assuming the graph is undirected
        }

        // Set diagonal elements to 0
        for (int i = 1; i <= n; ++i) graph[i][i] = 0;
        floydWarshall(graph, n);

        int q;
        cin >> q;
        while (q--) {
            int a, b; cin >> a >> b;
            if (graph[a][b] == INF) cout << 1e9 << endl;
            else cout << graph[a][b] << endl;
        }
    }
    return 0;
}

