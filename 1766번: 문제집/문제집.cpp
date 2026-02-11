#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int> adj[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> indegree(N+1, 0);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++; // 진입차수 +1
    }
    
    // 오름차순 정렬 우선순위 큐 -> 순서가 가장 낮은 문제부터 풀기
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";

        for (int nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
    
    
    return 0;
}