#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
int TC, N, M, W;

vector<pair<int, pair<int, long long>>> edges;
long long dist[501];

bool bellmanFord(int start) {
    dist[start] = 0;

    // N-1만큼 반복 후 N번째에 최단 거리 테이블이 갱신된다면 음수 사이클이 있다는 것
    // 음수 사이클이 있다 -> 한 지점에서 출발해서 그 지점으로 돌아올 때 시간이 줄어드는 게 가능하다.
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int from = edges[j].first;
            int to = edges[j].second.first;
            long long time = edges[j].second.second;
            // 한번이라도 갱신된 정점에 대해서만 다시 계산 시도 -> 단절된 정점은 계산 X
            // if (dist[from] == INF) continue;

            // 현재 간선을 거쳐서 다른 노드로 가는 거리가 더 짧을 때.
            if (dist[to] > dist[from] + time) {
                dist[to] = dist[from] + time; // 최단 거리 갱신

                // n번째에도 갱신되면 음수 사이클 존재
                if (i == N) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;
    
    while (TC--)
    {
        fill_n(dist, 501, INF);
        edges.clear();
        cin >> N >> M >> W;

        for (int i = 0; i < M; i++)
        {
            int S, E;
            long long T;
            cin >> S >> E >> T;
            // road[S][E] = min(road[S][E], T);
            // road[E][S] = min(road[E][S], T);
            edges.push_back({S, {E, T}});
            edges.push_back({E, {S, T}});
            // 두 지점을 연결하는 도로가 여러 개일 수 있음.
            // 문제에서 구하는 건 총 걸리는 시간이 0보다 작아야 하므로 도로간의 걸리는 시간이
            // 젤 작은 거로 세팅되게끔.
        }
        for (int i = 0; i < W; i++)
        {
            int S, E;
            long long T;
            cin >> S >> E >> T;
            edges.push_back({S, {E, -T}});
        }
        
        bool prob = bellmanFord(1);
        

        if (prob) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        
    }
    
    

    return 0;
}