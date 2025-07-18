#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct tomato {
    int x, y, z;
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dz[2] = {-1, 1};
// x, y, z
int box[101][101][101];
int m, n, h;

queue<tomato> q;

void bfs(void) {

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        // 상하좌우
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (box[nx][ny][z] == 0) {
                    box[nx][ny][z] = box[x][y][z] + 1;
                    q.push({nx, ny, z});
                }
            }
        }
        // 위아래
        for (int i = 0; i < 2; i++)
        {
            int nz = z + dz[i];
            if (0 <= nz && nz < h) {
                if (box[x][y][nz] == 0) {
                    box[x][y][nz] = box[x][y][z] + 1;
                    q.push({x, y, nz});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) // z
    {
        for (int j = 0; j < n; j++) // y
        {
            for (int k = 0; k < m; k++) // x
            {
                cin >> box[k][j][i];
                if (box[k][j][i] == 1) {
                    q.push({k, j, i});
                };
            }
        }
    }
    bfs();

    int ans = 0;
    for (int i = 0; i < h; i++) // z
    {
        for (int j = 0; j < n; j++) // y
        {
            for (int k = 0; k < m; k++) // x
            {
                if (box[k][j][i] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                ans = max(ans, box[k][j][i]);
            }
        }
    }
    cout << ans-1 << '\n';

    

    return 0;
}