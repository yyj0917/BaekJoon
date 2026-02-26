#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int T, I;

// 1분면부터 반시계방향으로
int night_move_dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int night_move_dc[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

pair<int, int> now_night, move_night;

int bfs() {
    queue<pair<int, int>> q;
    q.push({now_night.first, now_night.second});
    vector<vector<int>> dist(301, vector<int> (301, -1));
    dist[now_night.first][now_night.second] = 0;
    
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == move_night.first && c == move_night.second) {
            return dist[r][c];
        }

        for (int i = 0; i < 8; i++)
        {
            int nr = r + night_move_dr[i];
            int nc = c + night_move_dc[i];

            if (0 <= nr && nr < I && 0 <= nc && nc < I) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> I;
        cin >> now_night.first >> now_night.second;
        cin >> move_night.first >> move_night.second;
        cout << bfs() << "\n";
    }

    return 0;
}