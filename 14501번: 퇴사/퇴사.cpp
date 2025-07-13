#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> T(N), P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
    }

    vector<int> dp(N+1, 0); // 0으로 초기화

    for (int i = N-1; i >= 0; i--)
    {
        // 상담가능한경우
        if (i + T[i] <= N)
            dp[i] = max(P[i] + dp[i + T[i]], dp[i+1]);
        else 
            dp[i] = dp[i+1];
    }
    cout << dp[0] << endl;

    return 0;
}