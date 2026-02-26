#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int dp[201][201]; // 합이 i가 되도록 하는 정수 j개의 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int j = 1; j <= K; j++) 
        dp[0][j] = 1;
    
    for (int i = 0; i <= N; i++) 
        dp[i][1] = 1;
    
    for (int i = 0; i <= N; i++) 
        dp[i][2] = i + 1;
    
    
    for (int j = 2; j <= K; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }
    cout << dp[N][K];
    


    return 0;
}