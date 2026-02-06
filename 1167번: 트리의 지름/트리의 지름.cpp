#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int V;

vector<pair<int, int>> tree[100005];

int dist[100005];
int max_dist = -1, farthest_node = 0;

void dfs(int cur, int d) {
    dist[cur] = d;


    for (auto nxt : tree[cur]) {
        int nxt_node = nxt.first;
        int nxt_dist = nxt.second;
        if (dist[nxt_node] < 0) {
            if (max_dist < dist[cur] + nxt_dist) {
                max_dist = dist[cur] + nxt_dist;
                farthest_node = nxt_node;
            }
            dfs(nxt_node, dist[cur] + nxt_dist);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int u;
        cin >> u;
        while (true)
        {
            int v, w;
            cin >> v;
            if (v == -1) break;
            cin >> w;
            tree[u].push_back({v, w});
        }
    }
    memset(dist, -1, sizeof(dist));
    dfs(1, 0);

    memset(dist, -1, sizeof(dist));
    max_dist = -1;
    dfs(farthest_node, 0);
    
    cout << max_dist;

    return 0;
}