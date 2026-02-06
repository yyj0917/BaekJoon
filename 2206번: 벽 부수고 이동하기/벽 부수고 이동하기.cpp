#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9;
int N, M;

int map[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int min_dist = INF;


void bfs() {
    int dist[1001][1001][2];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
        }
    }
    queue<pair<pair<int,int>, int>> q; // {{r, c}, broken}
    q.push({{1,1}, 0});
    dist[1][1][0] = 1;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int broken = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
                if (map[nr][nc] == 0) {
                    if (dist[nr][nc][broken] > dist[r][c][broken] + 1) {
                        dist[nr][nc][broken] = dist[r][c][broken] + 1;
                        q.push({{nr, nc}, broken});
                    }
                    
                } 
                // 다음이 벽이지만, 아직 벽을 깬 적이 없을 때
                else if (map[nr][nc] == 1 && broken == 0) {
                    if (dist[nr][nc][1] > dist[r][c][0] + 1) {
                        dist[nr][nc][1] = dist[r][c][0] + 1;
                        q.push({{nr, nc}, 1});
                    }
                }
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << dist[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << dist[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    min_dist = min(dist[N][M][0], dist[N][M][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++) {
            map[i][j] = str[j-1] - '0';
        }
    }
    bfs();
    if (min_dist == INF) cout << -1;
    else cout << min_dist;

    return 0;
}