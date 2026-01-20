#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string first, second;
    cin >> first >> second;

    int dp[1001][1001];

    // 총 2가지
    // 1. i, j번째 수가 같을 때
    // 2. i, j번째 수가 다를 때
    int n = first.length();
    int m = second.length();
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (first[i-1] == second[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    
    

    return 0;
}