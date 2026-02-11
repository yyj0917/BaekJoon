#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> adj[N+1];
    vector<int> indegree(N+1, 0);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // 단방향 그래프 모델링
        indegree[v] += 1;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) { // 진입차수 0일 때
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (auto nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    

    return 0;
}