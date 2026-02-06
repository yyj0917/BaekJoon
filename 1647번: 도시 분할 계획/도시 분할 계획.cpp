#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;
int V, E;

vector<pair<int, int>> adj[100005];
int max_edge_cost = -1;
int total_weight = 0;

void solve_bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V+1, false);
    
    pq.push({0, 1}); // {weight, node}

    while (!pq.empty())
    {
        int cur_w = pq.top().first;
        int cur_v = pq.top().second;
        pq.pop();

        if (visited[cur_v]) continue; // 이미 방문했으면 방문 안 함
        visited[cur_v] = true;
        total_weight += cur_w;
        max_edge_cost = max(max_edge_cost, cur_w);

        for (auto nxt : adj[cur_v]) {
            int nxt_v = nxt.first;
            int nxt_w = nxt.second;
            if (!visited[nxt_v]) {
                pq.push({nxt_w, nxt_v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve_bfs();
    cout << total_weight - max_edge_cost;
    

    return 0;
}