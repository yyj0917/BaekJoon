#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int adj[m+1][n+1];
    int dist[m+1][n+1];
    memset(dist, -1, sizeof(dist));
    memset(adj, 0, sizeof(adj));
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++)
        {
            adj[j][i] = str[j-1] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 1;

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();
        q.pop();
    
        for (int k = 0; k < 4; k++)
        {
            int nx = cur_x + dx[k];
            int ny = cur_y + dy[k];
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {
                if (nx == m && ny == n) {
                    cout << dist[cur_x][cur_y]+1 << '\n';
                    return 0;
                } else {
                    if (adj[nx][ny] == 1 && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[cur_x][cur_y] + 1;
                        q.push({nx, ny});
                    }
                }
            } 

        }
    }

    
    return 0;
}