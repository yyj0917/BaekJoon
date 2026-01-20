#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> adj[10001];
bool visited[10001];
int n;
int max_dist = -1;
int farthest_node;

// node: 현재 방문 중인 노드
// cost: 시작점부터 여기까지 오는 데 걸린 누적 비용
void dfs(int node, int cost) {
    // 현재 노드 방문 처리
    visited[node] = true;

    // (여기서 필요한 로직 수행: 예 - 최댓값 갱신 등)
    // cout << node << " "; 
    if (max_dist < cost) {
        max_dist = cost;
        farthest_node = node;
    }

    // 인접한 노드 탐색
    for (auto& edge : adj[node]) {
        int next_node = edge.first;
        int weight = edge.second;

        // 방문하지 않은 곳만 들어감 (재귀 호출)
        if (!visited[next_node]) {
            
            dfs(next_node, cost + weight);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    

    
    memset(visited, false, sizeof(visited));
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(farthest_node, 0);

    cout << max_dist << "\n";
    

    return 0;
}