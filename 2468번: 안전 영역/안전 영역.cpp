#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;

int map[101][101];
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int max_height = 0;
int min_height = 1e9;

void dfs(int r, int c, int limit_h) {
    visited[r][c] = true;
    // cout << "r : " << r << " c : " << c << " limit_h : " << limit_h << endl;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (0 < nr && nr <= N && 0 < nc && nc <= N) {
            // cout << nr << " " << nc << " " << limit_h << " " << map[nr][nc] << endl;
            if (map[nr][nc] > limit_h && !visited[nr][nc]) {
                dfs(nr, nc, limit_h);
            }
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            max_height = max(max_height, map[i][j]);
            min_height = min(min_height, map[i][j]);
        }
    }

    int max_area = 1;
    for (int h = min_height; h <= max_height; h++) {
        // visited 초기화
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                visited[r][c] = false;
            }
        }
        int safety_area = 0;
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (!visited[r][c] && map[r][c] > h) {
                    dfs(r, c, h);
                    safety_area++;
                }
            }
        }
        max_area = max(max_area, safety_area);
    }
    cout << max_area;


    return 0;
}