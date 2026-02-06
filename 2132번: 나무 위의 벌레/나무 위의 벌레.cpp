#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

vector<int> adj[10005];
vector<long long> fruit(10005);
bool visited[10005];
int order = 1;


long long max_dist = -1;
int max_node = 10005;

void dfs(int cur_node, long long cost) {
    visited[cur_node] = true;

    // 비용 계산 로직
    if (max_dist < cost) {
        max_dist = cost;
        max_node = cur_node;
    } else if (max_dist == cost) max_node = min(max_node, cur_node);

    for (auto nxt : adj[cur_node]) {
        if (!visited[nxt]) {
            dfs(nxt, cost + fruit[nxt]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> fruit[i];
    }

    int u, v;
    while (cin >> u >> v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 트리의 지름
    // 아무 정점을 잡고 dfs를 했을 때 가장 멀리있는 노드는 지름의 끝점
    // 얻은 지름의 끝점 하나로 다시 dfs하면 그것이 가장 멀리있는 지름의 끝점들

    // 임의의 지점에서 가장 먼 끝점 찾기
    memset(visited, false, sizeof(visited));
    dfs(1, fruit[1]);

    int first_end_node = max_node;

    max_dist = -1;
    max_node = 10005;
    memset(visited, false, sizeof(visited));

    // first_end_node에서 가장 끝점 찾기
    dfs(first_end_node, fruit[first_end_node]);

    int second_end_node = max_node;

    // 두 값중 최솟값 구하기

    cout << max_dist << " " << min(first_end_node, second_end_node) << "\n";
    
    return 0;
}