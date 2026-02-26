#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int map[1001][1001];
int copy_map[1001][1001];
int group[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int cnt = 0;
void dfs(int r, int c, int group_num) {
    group[r][c] = group_num;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr <= 0 || nr > N || nc <= 0 || nc > M) continue;

        if (group[nr][nc] == 0 && map[nr][nc] == 0) {
            dfs(nr, nc, group_num);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<pair<int, int>> walls;
    vector<pair<int, int>> blanks;

    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j+1] = str[j] - '0';
            copy_map[i][j+1] = map[i][j+1];
            if (map[i][j+1] == 1) walls.push_back({i, j+1});
            else blanks.push_back({i, j+1});
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            group[i][j] = 0;
        }
    }
    int group_num = 1;
    vector<int> group_size(1000001, 0);
    for (auto& pair : blanks) {
        int r = pair.first;
        int c = pair.second;
        cnt = 0;
        if (group[r][c] != 0) continue;
        dfs(r, c, group_num);
        group_size[group_num] = cnt;
        group_num++;
    }

    for (auto& pair : walls) {
        int r = pair.first;
        int c = pair.second;
        int sum = 1; // 자기 자신 포함
        int near_groups[4]; // 인접한 최대 4개의 그룹 ID 저장
        int group_cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
            bool already_added = false;
            for (int j = 0; j < group_cnt; j++) {
                if (near_groups[j] == group[nr][nc]) {
                    already_added = true; break;
                }
            }
            if (!already_added) {
                sum += group_size[group[nr][nc]];
                near_groups[group_cnt++] = group[nr][nc];
            }
        }
        copy_map[r][c] = sum % 10;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << copy_map[i][j];
        }
        cout << "\n";
    }

    return 0;
}