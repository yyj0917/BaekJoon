#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
const int INF = 1e9;
int V, E;
struct UnionFind {
    vector<int> parent;

    // 초기화: 처음에는 자기 자신이 자기의 부모(대장)입니다.
    UnionFind(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 0, 1, 2, ..., n으로 채움
    }

    // Find: x의 대장을 찾음 (경로 압축 최적화 포함)
    int find(int x) {
        if (parent[x] == x) return x;
        // 경로 압축(Path Compression): 찾으러 올라가는 길에 만난 모든 노드를 
        // 직접 대장에게 연결해서 다음 검색 속도를 비약적으로 높입니다.
        return parent[x] = find(parent[x]);
    }

    // Union: x가 속한 팀과 y가 속한 팀을 합침
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // 한쪽 대장을 다른 쪽 대장 밑으로 보냅니다.
            parent[rootX] = rootY;
        }
    }

    // 같은 집합에 있는지 확인
    bool isSame(int x, int y) {
        return find(x) == find(y);
    }
};

// vector<pair<int, int>> adj[10005];
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};

// void solve_bfs() {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     vector<bool> visited(V+1, false);
    
//     pq.push({0, 1}); // {weight, node}

//     while (!pq.empty())
//     {
//         int cur_w = pq.top().first;
//         int cur_v = pq.top().second;
//         pq.pop();

//         if (visited[cur_v]) continue; // 이미 방문했으면 방문 안 함
//         visited[cur_v] = true;
//         total_weight += cur_w;

//         for (auto nxt : adj[cur_v]) {
//             int nxt_v = nxt.first;
//             int nxt_w = nxt.second;
//             if (!visited[nxt_v]) {
//                 pq.push({nxt_w, nxt_v});
//             }
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    // for (int i = 0; i < E; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     adj[u].push_back({v, w});
    //     adj[v].push_back({u, w});
    // }
    vector<Edge> edges(E+1);
    for (int i = 1; i <= E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // adj[u].push_back({w, v});
        // adj[v].push_back({w, u});
        edges[i] = {u, v, w};
    }

    // 크루스칼을 위한 오름차순 정렬 - 젤 가중치가 작은 게 맨앞에 가도록
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    int edges_cnt = 0;
    long long total_weight = 0;

    for (auto& edge : edges) {
        // 두 점의 부모가 다른지 확인 (사이클 방지 및 간선 연결을 위해)
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v); // 연결하기
            total_weight += edge.w; // 연결했다는 건 가중치를 추가해도 된다는 으미
            edges_cnt++;
        }
        if (edges_cnt == V - 1) break; // 필요한 모든 간선을 연결했음.
    }
    

    cout << total_weight;
    

    return 0;
}