#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int L = 0, R = 0;
int dp[100001][5][5];

int min_strong(int now_loc, int move_loc) {
    if (now_loc == 0) {
        return 2;
    } else if (now_loc == 1) {
        if (move_loc == now_loc) return 1;
        else if (move_loc == 2 || move_loc == 4) return 3;
        else return 4;
    } else if (now_loc == 2) {
        if (move_loc == now_loc) return 1;
        else if (move_loc == 1 || move_loc == 3) return 3;
        else return 4;
    } else if (now_loc == 3) {
        if (move_loc == now_loc) return 1;
        else if (move_loc == 2 || move_loc == 4) return 3;
        else return 4;
    } else {
        if (move_loc == now_loc) return 1;
        else if (move_loc == 1 || move_loc == 3) return 3;
        else return 4;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> instruction;
    // i번째 명령어를 수행했을 때 왼발이 L,오른발이 R에 있을 때의 최소 힘.
    for (int k = 0; k < 100001; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dp[k][i][j] = 1e9;
            }
        }
    }
    
    
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        instruction.push_back(n);
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < instruction.size(); i++)
    {
        int n = instruction[i];
        for (int L = 0; L < 5; L++) {
            for (int R = 0; R < 5; R++) {
                // 1. 현재 상태가 도달 가능한 상태인지 확인 (INF가 아닌지)
                if (dp[i][L][R] == 1e9) continue;

                // 2. 왼발을 n으로 옮기는 경우
                // 단, 옮긴 후의 왼발(n)과 오른발(R)이 같으면 안 됨 (n != R)
                if (n != R) {
                    dp[i + 1][n][R] = min(dp[i + 1][n][R], dp[i][L][R] + min_strong(L, n));
                }

                // 3. 오른발을 n으로 옮기는 경우
                // 단, 옮긴 후의 오른발(n)과 왼발(L)이 같으면 안 됨 (n != L)
                if (n != L) {
                    dp[i + 1][L][n] = min(dp[i + 1][L][n], dp[i][L][R] + min_strong(R, n));
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ans = min(ans, dp[instruction.size()][i][j]);
        }
    }

    cout << ans;

    return 0;
}