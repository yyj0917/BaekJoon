#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int dp[101][10];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][1];
                continue;
            }
            if (j == 9) {
                dp[i][j] = dp[i-1][8];
                continue;
            }
            dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % 1000000000;
        }
    }
    long long res = 0;
    for (int i = 0; i < 10; i++) res += dp[N][i] % 1000000000;

    cout << res % 1000000000;
    return 0;
}