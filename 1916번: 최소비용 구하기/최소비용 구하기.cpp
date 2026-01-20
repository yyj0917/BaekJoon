#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<pair<int, int>> adj[1001]; // adj[출발지] = {도착지 , 비용}
    vector<long long> dist(1001, inf);

    for (int i = 1; i <= m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        adj[start].push_back({end, weight});
    }
    int start_city, end_city;
    cin >> start_city >> end_city;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start_city] = 0;
    pq.push({0, start_city});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue; // 이미 최단거리로 방문했으면 넘긴다

        for (auto next_pair : adj[node]) {
            int next_node = next_pair.first;
            int weight = next_pair.second;

            if (dist[next_node] > cost + weight) {
                dist[next_node] = cost + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    
    cout << dist[end_city] << "\n";
    


    return 0;
}