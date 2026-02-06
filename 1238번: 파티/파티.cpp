#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M, X;
const int INF = 1e9;

vector<int> T; // i번째 도로에서 필요한 소요시간 T_i;

int dist[1001];

void dijkstra(int cur, vector<pair<int, int>> road[]) {
    fill(dist, dist + N + 1, INF);    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur}); // {dist, node}
    dist[cur] = 0;

    while (!pq.empty())
    {
        int cur_t = pq.top().first;
        int cur_v = pq.top().second;
        pq.pop();

        // 이미 처리된 거리가 더 짧다면 무시
        if (cur_t > dist[cur_v]) continue;

        for (auto& nxt : road[cur_v]) {
            int nxt_v = nxt.first;
            int nxt_t = nxt.second;

            if (dist[nxt_v] > dist[cur_v] + nxt_t) {
                dist[nxt_v] = dist[cur_v] + nxt_t;
                pq.push({dist[nxt_v], nxt_v});
            }
        }
    }
    
    // return dist[destination];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    T.push_back(0); // index base를 1부터 시작하려고
    vector<pair<int, int>> right_road[N+1];
    vector<pair<int, int>> reverse_road[N+1];
    
    for (int i = 0; i < M; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        right_road[u].push_back({v, t});
        reverse_road[v].push_back({u, t});
        T.push_back(t);
    }

    vector<int> result(N+1, 0);

    dijkstra(X, right_road);
    for (int i = 1; i <= N; i++)
    {
        result[i] = dist[i];
    }
    
    dijkstra(X, reverse_road);
    for (int i = 1; i <= N; i++)
    {
        result[i] += dist[i];
    }
    
    int max_time = -1;
    for (int i = 1; i <= N; i++)
    {
        max_time = max(max_time, result[i]);
    }
    

    
    cout << max_time;
    
    return 0;
}