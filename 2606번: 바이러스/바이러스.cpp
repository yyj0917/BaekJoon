#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

void dfs(const vector<vector<int>>& adj, int cur, vector<bool>& visited) {
    visited[cur] = true;

    for (int next : adj[cur]) {
        if (!visited[next]) {
            visited[next] = true;
            dfs(adj, next, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;

    int e;
    cin >> e;
    vector<vector<int>> adj(v+1);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(v+1, false);
    dfs(adj, 1, visited);

    int cnt = 0;
    for (int i = 0; i <= v; i++)
    {
        if (visited[i]) cnt++;
    }
    cout << cnt - 1 << '\n';
    
    return 0;
}