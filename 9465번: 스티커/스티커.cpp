#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
       int sticker[3][n];
       for (int j = 0; j < 3; j++)
       {
            if (j == 0) {
                for (int k = 1; k <= n; k++)
                {
                   sticker[j][k] = 0;
                }
                
            }
            else {
                for (int k = 1; k <= n; k++)
                {
                    cin >> sticker[j][k];
                }
            }
       }
       int dp[3][n+1];
       dp[0][0] = 0;
       dp[1][0] = 0;
       dp[2][0] = 0;
       for (int j = 1; j <= n; j++)
       {
            dp[0][j] = max(dp[1][j-1], dp[2][j-1]) + sticker[0][j];
            dp[1][j] = max(dp[0][j-1], dp[2][j-1]) + sticker[1][j];
            dp[2][j] = max(dp[0][j-1], dp[1][j-1]) + sticker[2][j];
       }
       int ans = -1;
       for (int j = 0; j < 3; j++)
       {
            ans = max(ans, dp[j][n]);
       }
       cout << ans << '\n';

    }
    

    return 0;
}