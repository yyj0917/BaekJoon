#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

const long long MAX = 1e9;

int N, M;
int adj[105][105];// { end_node, cost }
void floid(int pass) {

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            adj[i][j] = min(adj[i][j], adj[i][pass] + adj[pass][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) {
        adj[i][j] = MAX;
    }

    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
    }

    for (int i = 1; i <= N; i++)
    {
        floid(i);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (adj[i][j] >= MAX || i == j) cout << 0;
            else cout << adj[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    
    

    
    

    return 0;
}