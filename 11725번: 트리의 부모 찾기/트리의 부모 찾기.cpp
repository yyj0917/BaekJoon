#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> parent;
vector<bool> visited;

void dfs(int cur, vector<vector<int>> &node) {
    visited[cur] = true;

    for (int next : node[cur]) {
        if (!visited[next]) {
            parent[next] = cur;
            dfs(next, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<vector<int>> node(n+1);
    parent.resize(n+1);
    visited.resize(n+1, false);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    
    dfs(1, node);

    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << '\n';
    }
    
    

    return 0;
}