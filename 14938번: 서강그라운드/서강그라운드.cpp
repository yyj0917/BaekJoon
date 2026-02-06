#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
int N, M, R;

vector<int> item(105);
int dist[105][105]; // {ground, dist}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }   
    }

    // item 수 채우기
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < R; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // 중복 간선 대비
        dist[v][u] = min(dist[v][u], w);
    }
    

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int max_items = 0;
    for (int i = 1; i <= N; i++) {
        int current_total = 0;
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] <= M) { // 최단 거리가 수색 범위(M) 이내일 때
                current_total += item[j];
            }
        }
        max_items = max(max_items, current_total);
    }

    return 0;
}