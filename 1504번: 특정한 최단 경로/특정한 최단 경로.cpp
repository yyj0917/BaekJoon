#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int inf = 1e9;
vector<pair<int, int>> adj[801];

int solution(
int start_point, int end_point) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(801, inf);

    pq.push({0, start_point});
    dist[start_point] = 0;
    while (!pq.empty())
    {
       int cur_cost = pq.top().first;
       int cur_node = pq.top().second;
       pq.pop();

       if (cur_cost > dist[cur_node]) continue;

       for (auto& next_pair : adj[cur_node]) {
            int next_cost = next_pair.second;
            int next_node = next_pair.first;
            if (dist[next_node] > cur_cost + next_cost) {
                dist[next_node] = cur_cost + next_cost;
                pq.push({dist[next_node], next_node});
            }
       }
    }
    return dist[end_point];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    
    if (e == 0) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int ans1 = inf, ans2 = inf, ans3 = inf;
    int sum = 0;

    ans1 = solution(1, v1);
    ans2 = solution(v1, v2);
    ans3 = solution(v2, n);

    sum = ans1 + ans2 + ans3;

    ans1 = solution(1, v2);
    ans2 = solution(v2, v1);
    ans3 = solution(v1, n);

    sum = min(ans1 + ans2 + ans3, sum);


    if (sum < inf) {
        cout << sum << "\n";
    } else cout << -1 << "\n";
    

    return 0;
}