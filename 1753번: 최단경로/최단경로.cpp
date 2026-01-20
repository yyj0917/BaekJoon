#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;

    vector<pair<int, int>> adj[20001];


    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(20001, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue;


        for (auto& next_pair : adj[node]) {
            int next_node = next_pair.first;
            int next_cost = next_pair.second;
            if (dist[next_node] > cost + next_cost) {
                dist[next_node] = cost + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    
    for (int i = 1; i <= v; i++)
    {
        if (start == i) cout << 0 << "\n";
        else {
            if (dist[i] == inf) cout << "INF" << "\n";
            else cout << dist[i] << "\n";
        }
    }

    
    


    
    

    return 0;
}