#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, Q;
vector<int> adj[100005];
vector<pair<int, int>> edges;
int disc[100005];
int low[100005];
int t = 0;
vector<bool> isArticulation(100005);

void dfs(int cur, int parent, bool isRoot) {
    disc[cur] = ++t;

    low[cur] = t; // Case 1
    int childCount = 0;

    for (auto nxt : adj[cur]) {
        if (nxt == parent) continue;
        if (disc[nxt] == -1) { // Case 2
            childCount++;
            dfs(nxt, cur, false); // child는 not root
            low[cur] = min(low[cur], low[nxt]);

            // 일반적인 단절점 조건
            if (!isRoot && low[nxt] >= disc[cur]) {
                isArticulation[cur] = true;
            }
        } else {
            low[cur] = min(low[cur], disc[nxt]);
        }
    }

    // root node일 때
    if (isRoot && childCount >= 2) {
        isArticulation[cur] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    edges.push_back({0, 0});
    for (int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));

    for (int i = 1; i <= N; i++) {
        if (disc[i] == -1) { // 아직 방문하지 않은 정점 발견!
            // 여기서 시작하는 i는 이 DFS 트리의 '루트'임
            dfs(i, -1, true); 
        }
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int t, k;
        cin >> t >> k;

        if (t == 1) { // 단절점 케이스
            if (isArticulation[k]) cout << "yes";
            else cout << "no";
        } else { // 단절선 케이스
            int u = edges[k].first;
            int v = edges[k].second;

            // 방문 순서가 뒤인 쪽이 자식
            // 자식의 low가 부모의 disc보다 크면 단절선이니까
            if (disc[u] > disc[v]) swap(u, v);
            if (low[v] > disc[u]) cout << "yes";
            else cout << "no";
        }
        cout << "\n";
    }
        
    return 0;
}