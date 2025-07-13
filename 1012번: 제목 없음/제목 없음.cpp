#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int t, m, n, k;
int adj[51][51];
bool visited[51][51];

// void dfs(int (&adj)[51][51], int x, int y, bool (&visited)[51][51]) {
//     visited[x][y] = true;

//     for (int i = 0; i < 4; i++)
//     {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
//         if (adj[nx][ny] == 1 && !visited[nx][ny]) {
//             dfs(adj, nx, ny, visited);
//         }
//        }
//     }
// }

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
       auto [cur_x, cur_y] = q.front(); 
       q.pop();

       for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (adj[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
       }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> m >> n >> k;
        memset(visited, false, sizeof(visited));
        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == 1) {
                    if (!visited[i][j]) {
                        bfs(i, j);
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << '\n';
        
    }
    return 0;
}