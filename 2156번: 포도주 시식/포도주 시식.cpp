#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> grape(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> grape[i];
    }

    // dp[현재 마시는 포도주 번호][직전에 연속으로 마신 포도주 개수] = 의 최댓값
    // vector<int> dp(n+1, 0);
    
    // dp[1] = grape[1];
    // dp[2] = dp[1] + grape[2];
    // dp[3] = max(dp[2], max(dp[1] + grape[3], grape[2] + grape[3]));
    // dp[0] = 0;
    // for (int i = 4; i <= n; i++)
    // {
    //     // 이번 잔을 마시지 않는다
    //     // 이번 잔을 마시고, 직전 잔은 안 마심
    //     // 이번 잔을 마시고, 직전 잔도 마심
    //     dp[i] = max(dp[i-1], max(grape[i] + dp[i-2], grape[i] + grape[i-1] + dp[i-3]));
    // }
    // cout << dp[n];
    int dp[n+2][3];
    
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[1][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        // i번째 안 마실 때
        dp[i+1][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));

        // i번째 마실 때
        dp[i+1][1] = dp[i][0] + grape[i];
        dp[i+1][2] = dp[i][1] + grape[i];
    }
    cout << max(dp[n+1][0], max(dp[n+1][1], dp[n+1][2]));

    return 0;
}