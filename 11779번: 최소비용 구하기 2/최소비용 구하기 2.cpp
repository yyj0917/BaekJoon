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

    int n, m, start_city, end_city;
    cin >> n >> m;
    
    vector<pair<int,int>> adj[1001]; // first : dest_node, second : cost
    vector<int> dist(1001, inf);
    vector<int> parent(1001); // parent[v] = u -> 노드 v에 도달하기 이전의 노드 u

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> start_city >> end_city;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_city}); // {cost , next_node}
    dist[start_city] = 0;

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (cur_cost > dist[cur_node]) continue; // 현재 지나려는 경로의 비용이 최단 비용보다 크면 처리하지 않음
        
        for (auto& next_pair : adj[cur_node]) {
            int next_cost = next_pair.second;
            int next_node = next_pair.first;
            if (dist[next_node] > cur_cost + next_cost) {
                dist[next_node] = cur_cost + next_cost;
                parent[next_node] = cur_node;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    // 그냥 최소 비용 출력
    cout << dist[end_city] << "\n";

    // 경로 역추적
    vector<int> path;
    int cur = end_city; // 시작으로 돌아가니까
    path.push_back(cur);


    while (true)
    {
        if (start_city == parent[cur]) {
            path.push_back(start_city);
            break;
        }
        cur = parent[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    
    
    return 0;
}