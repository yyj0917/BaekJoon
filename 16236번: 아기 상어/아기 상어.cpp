#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct Result {
    int r, c, time;
};

int N;
int map[21][21];
vector<pair<int, int>> fish[7]; // fish[size] = {fish_r, fish_c}

pair<int, int> baby_shark;
int baby_shark_size = 2;
int eat_cnt = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

Result solve() { // bfs
    int check[21][21] = {0};
    queue<pair<int, int>> q; // {{r, c}, shark_size}
    vector<Result> candidates; // 먹을 수 있는 후보들
    q.push({baby_shark.first, baby_shark.second});
    check[baby_shark.first][baby_shark.second] = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > N || check[nr][nc]) continue;

            // 지날 수 있는 경우 (아기상어보다 물고기가 안 클 때)
            if (map[nr][nc] <= baby_shark_size) {
                check[nr][nc] = check[r][c] + 1; // 방문 표시
                q.push({nr, nc});

                // 먹을 수 있는 경우 (아기상어보다 크기가 안 크고, 빈칸이 아닐 때)
                if (map[nr][nc] > 0 && map[nr][nc] < baby_shark_size) {
                    candidates.push_back({nr, nc, check[nr][nc]-1});
                }
            }
        }
    }
    if (candidates.empty()) return {-1, -1, -1};

    sort(candidates.begin(), candidates.end(), [](Result a, Result b) {
        if (a.time != b.time) return a.time < b.time;
        if (a.r != b.r) return a.r < b.r;
        return a.c < b.c;
    });

    return candidates[0];
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 6) {
                fish[map[i][j]].push_back({i, j});
            } else if (map[i][j] == 9) {
                baby_shark = {i, j};
                map[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < 7; i++)
    {
        sort(fish[i].begin(), fish[i].end()); // 각 크기에 있는 물고기들을 정렬 - 젤 위에 있고, 젤 왼쪽에 있는 물고기를 앞에 내세우기 위해
    }
    int take_time = 0;
    while (true)
    {
        Result res = solve();
        if (res.r == -1 && res.c == -1 && res.time == -1) break;
        take_time += res.time;
        eat_cnt += 1;
        baby_shark = {res.r, res.c};
        map[res.r][res.c] = 0;
        if (eat_cnt == baby_shark_size) {
            eat_cnt = 0;
            baby_shark_size++;
        }
    }
    cout << take_time;
    

    return 0;
}