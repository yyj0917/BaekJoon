#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int, int>> adj[1005];
bool visited[1005];

void dfs(int start, int end, int cost) {
    if (start == end) {
        cout << cost << "\n";
        return;
    }
    visited[start] = true;

    for (auto nxt : adj[start]) {
        int nxt_node = nxt.first;
        int nxt_cost = nxt.second;
        if (!visited[nxt_node]) {
            dfs(nxt_node, end, cost + nxt_cost);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for (int i = 1; i <= N-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        memset(visited, false, sizeof(visited));
        dfs(u, v, 0);
    }
    
    

    return 0;
}