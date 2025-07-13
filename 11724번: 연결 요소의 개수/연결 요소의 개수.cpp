#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int v,e;

void dfs (vector<vector<int>> &adj, int cur, vector<bool> &visited) {
    visited[cur] = true;

    for (int next: adj[cur]) {
        if (!visited[next]) {
            dfs(adj, next, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    vector<bool> visited(v+1);
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cc = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i]) {
            dfs(adj, i, visited);
            cc++;
        }
    }
    
    cout << cc << '\n';

    return 0;
}