#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long dp[1001][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    
    for (int i = 0; i < 10; i++) dp[1][i] = 1;
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0]; // j가 0일 때는 이전 단계의 값을 그대로 가져옴
        for (int j = 1; j < 10; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;        
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += dp[N][i];
    }
    
    cout << ans % 10007;

    return 0;
}