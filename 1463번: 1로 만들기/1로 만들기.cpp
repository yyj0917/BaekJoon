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

    int dp[n+1];
    dp[1] = 0;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1; // 1 빼는 거
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1); // 2로 나누는 거, 1 빼는 거 중에 뭐가 최소일지
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    cout << dp[n] << endl;

    return 0;
}