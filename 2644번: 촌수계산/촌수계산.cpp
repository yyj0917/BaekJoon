#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, m, ans_num1, ans_num2;

vector<pair<int, int>> adj[105];
bool visited[105];

bool dfs(int start, int end, int cost) {
    if (start == end) {
        cout << cost;
        return true;
    }
    visited[start] = true;

    for (auto nxt : adj[start]) {
        int nxt_node = nxt.first;
        int nxt_cost = nxt.second;
        if (!visited[nxt_node]) {
            if (dfs(nxt_node, end, cost + nxt_cost)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> ans_num1 >> ans_num2 >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    if (!dfs(ans_num1, ans_num2, 0)) {
        cout << -1;
    }


    

    return 0;
}