#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int R, C, T;
int ans = 0;

int dc[4] = {-1, 1, 0, 0};
int dr[4] = {0, 0, -1, 1};

int board[51][51];
int dust_add_board[51][51]; // 확산된 양만 저장할 배열
vector<int> airCleaner; // 공기 청정기 col = 1로 고정이므로 row를 저장.

void dust_broadcast() { // 미세먼지 확산 함수
    // 확산될 양을 저장할 배열 초기화
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) dust_add_board[i][j] = 0;

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            
            if (board[i][j] <= 0) continue;

            int res = board[i][j]/5;
            int broad_cnt = 0;

            // 주변 확산시키는 로직
            for (int k = 0; k < 4; k++)
            {
                int nxt_r = i + dr[k];
                int nxt_c = j + dc[k];

                if (nxt_r <= R && nxt_r > 0 && nxt_c <= C && nxt_c > 0) {
                    if (board[nxt_r][nxt_c] == -1) continue; // 공기청정기 칸 제외
                    dust_add_board[nxt_r][nxt_c] += res;
                    broad_cnt++;
                }
            }
            board[i][j] -= (res * broad_cnt);
        }
    }
    // 확산된 먼지 합치기
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (board[i][j] != -1) board[i][j] += dust_add_board[i][j];
}

void air_clean() { // 공기 청정기 바람
    int f_row = airCleaner[0];
    int s_row = airCleaner[1];

    // 1. col 1에서 먼저 공기청정기쪽으로 밀어보내기
    for (int i = f_row-1; i >= 1; i--)
    {
        if (i == 1) board[i][1] = 0;
        else board[i][1] = board[i-1][1];
    } 
    for (int i = s_row+1; i <= R; i++)
    {
        if (i == R) board[i][1] = 0;
        else board[i][1] = board[i+1][1];
    }
    // 2. row 1, row R에서 왼쪽으로 밀어보내기
    for (int i = 1; i <= C; i++)
    {
        if (i == C) {
            board[1][i] = 0;
            board[R][i] = 0;
        }
        else {
            board[1][i] = board[1][i+1];
            board[R][i] = board[R][i+1];
        }
    }
    // 3. col C에서 f_row, s_row 각 기준으로 위/아래로 밀어보내기
    for (int i = 1; i <= f_row; i++)
    {
        if (i == f_row) board[i][C] = 0;
        else board[i][C] = board[i+1][C];
    }
    for (int i = R; i >= s_row; i--)
    {
        if (i == s_row) board[i][C] = 0;
        else board[i][C] = board[i-1][C];
    }
    // 4. f_row, s_row 각 기준으로 오른쪽으로 밀어보내기
    for (int i = C; i >= 2; i--)
    {
        if (i == 2) board[f_row][i] = 0;
        else board[f_row][i] = board[f_row][i-1];
    }
    for (int i = C; i >= 2; i--)
    {
        if (i == 2) board[s_row][i] = 0;
        else board[s_row][i] = board[s_row][i-1];
    }
}

void solve_ans() { // 남아있는 미세먼지의 양
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j] > 0) ans += board[i][j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> T;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++){
            cin >> board[i][j];
            if (board[i][j] == -1) airCleaner.push_back(i);
        }
    }
    
    for (int i = 0; i < T; i++)
    {
        dust_broadcast();
        air_clean();
    }
    solve_ans();
    cout << ans;
    // for (int i = 1; i <= R; i++) {
    //     for (int j = 1; j <= C; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    
    
    return 0;
}