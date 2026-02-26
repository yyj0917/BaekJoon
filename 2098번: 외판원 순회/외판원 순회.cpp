#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;

int N;
// 집합 mask에 속한 도시들을 모두 돌고, 현재 curr에 있을 때의 최소 비용
int dp[1 << 16][16];
int W[17][17];

// 현재 curr도시에 있고, 방문 상태가 mask일 때 남은 도시들을 모두 방문하고 다시 시작점으로 돌아가는 데 드는 최소 비용
int solve(int curr, int mask) {
    // base case - 모든 도시 방문
    if (mask == (1 << N) - 1) {
        // 현재 도시이자 마지막 도시에서 시작점으로 돌아가는 경로 확인
        return W[curr][0] == 0 ? INF : W[curr][0];
    }

    // memoization
    if (dp[mask][curr] != -1) return dp[mask][curr];

    dp[mask][curr] = INF;

    // next visit city search
    for (int next = 0; next < N; next++)
    {
        // 길이 있고, 아직 방문하지 않았다면
        if (W[curr][next] != 0 && !(mask & (1 << next))) {
            // 지금 가는 비용 + next 도시로 돌아오는 비용
            int res = solve(next, mask | (1 << next));

            // 경로가 유효하다면 최소 비용 갱신
            if (res != INF) {
                dp[mask][curr] = min(dp[mask][curr], W[curr][next] + res);
            }
        }
    }
    return dp[mask][curr];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            cin >> w;
            W[i][j] = w;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);

    return 0;
}