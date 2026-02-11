#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int T, N, K;

int topological_sort(int w, vector<int> &indegree, vector<int> &outdegree, vector<int> adj[], vector<int> &time) {
    queue<int> q; // 진입차수가 0인 노드들
    vector<int> result(1005, 0);
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = time[i]; // 자기 건물 짓는 시간
        }
    }
    while (!q.empty())
    {
        int cur_node = q.front();
        q.pop();

        for (auto nxt : adj[cur_node])
        {
            --outdegree[cur_node];
            result[nxt] = max(result[nxt], result[cur_node] + time[nxt]);
            if (--indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    
    return result[w];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        vector<int> adj[1005];
        vector<int> indegree(1005, 0); // 진입차수
        vector<int> outdegree(1005, 0); // 진출차수
        vector<int> time(1005);
        int target_city;
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }
        for (int i = 1; i <= K; i++) {
            // u는 시작점, v는 도착점
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        cin >> target_city;
        int ans = topological_sort(target_city, indegree, outdegree, adj, time);
        cout << ans << "\n";
    }
    

    return 0;
}