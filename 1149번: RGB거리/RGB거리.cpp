#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int rgb[1001][1001];

    // 순서대로 red, green, blue;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            cin >> rgb[i][j];
        }
    }
    int dp[1001][3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
       ans = min(ans, dp[n][i]);
    }
    
    cout << ans << '\n';

    return 0;
}