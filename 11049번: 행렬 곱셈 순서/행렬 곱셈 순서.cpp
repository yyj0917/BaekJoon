#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct Matrix {
    int r, c;
};

int N;
vector<Matrix> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    m.resize(N+1);
    for (int i = 1; i <= N; i++)
    {
        int r, c;
        cin >> r >> c;
        m[i].r = r;
        m[i].c = c;
    }
    long long dp[N+1][N+1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 4e12;
        }
    }
    
    for (int len = 1; len < N; len++) // 구간의 길이
    {
        for (int i = 1; i <= N-len; i++) // 시작 지점
        {
            int j = i + len; // 끝 지점
            
            for (int k = i; k < j; k++)
            {
                long long cost = dp[i][k] + dp[k+1][j] + (m[i].r * m[k].c * m[j].c);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[1][N];
    

    return 0;
}