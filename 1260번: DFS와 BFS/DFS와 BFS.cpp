#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void dfs(int cur, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[cur] = true;
    cout << cur << ' ';
    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next, visited, adj);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;

    vector<vector<int>> adj(v+1);

    for (int i = 0; i < e; i++)
    {
        int start_v, end_v;
        cin >> start_v >> end_v;
        adj[start_v].push_back(end_v);
        adj[end_v].push_back(start_v);
    }
    

    for (int i = 1; i <= v; i++)
    {
       sort(adj[i].begin(), adj[i].end());
    }
    
    
    // DFS
    vector<bool> visited_dfs(v+1, false);
    dfs(start, visited_dfs, adj);
    cout << '\n';

    // BFS
    queue<int> bfs_q;
    vector<bool> visited(v+1, false);

    bfs_q.push(start);
    visited[start] = true;
    cout << start;

    while (!bfs_q.empty()) {
        int cur = bfs_q.front();
        bfs_q.pop();

        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                cout << ' ' << next;
                bfs_q.push(next);

            }
        }
    }
    cout << '\n';
    return 0;
}