#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long dp[1000001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 0; i < N; i++)
    {
        dp[i+2] = (dp[i] + dp[i+1]) % 15746;
    }
    cout << dp[N+1];
    



    return 0;
}