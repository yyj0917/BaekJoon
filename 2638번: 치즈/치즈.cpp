#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M; // N = row, M = column

int cheese_cnt = 0;
int map[101][101];
int copy_map[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<pair<int, int>> melt_ch;
void melt() {
    // queue<pair<int, int>> q;

    // q.push({1, 1});

    // while (!q.empty())
    // {
    //     int r = q.front().first;
    //     int c = q.front().second;
    //     q.pop();
    //     if (copy_map[r][c] != 1) continue;

    //     int melt_cnt = 0;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int nr = r + dr[i];
    //         int nc = c + dc[i];
    //         if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
    //             if (copy_map[nr][nc] == -1) {
    //                 melt_cnt++;
    //             } 
    //         }
    //     }
    // }
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= M; c++)
        {
            if (map[r][c] != 1) continue;

            int melt_cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
                    if (map[nr][nc] == 2) {
                        melt_cnt++;
                    } 
                }
            }
            if (melt_cnt >= 2) melt_ch.push_back({r, c});
        }
    }
    for (auto p : melt_ch) {
        int melt_r = p.first;
        int melt_c = p.second;
        map[melt_r][melt_c] = 0;
        cheese_cnt--;
    }
    
}

void airChange() { // 치즈를 녹이지 않는 공기를 정하는 함수
    queue<pair<int, int>> q;
    for (int i = 0; i < melt_ch.size(); i++)
    {
        q.push({melt_ch[i].first, melt_ch[i].second});
        map[melt_ch[i].first][melt_ch[i].second] = 2;
    }
    
    q.push({1, 1});
    map[1][1] = 2;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (map[r][c] == 1) continue;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
                if (map[nr][nc] == 0) {
                    map[nr][nc] = 2;
                    q.push({nr, nc});
                } 
            }
        }
    }
    melt_ch.clear(); // 녹일 치즈 초기화
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1) cheese_cnt++;
        }
    }
    int time = 0;
    while (cheese_cnt > 0)
    {
        time++;
        airChange();
        melt();
    }
    cout << time;
    
    

    return 0;
}