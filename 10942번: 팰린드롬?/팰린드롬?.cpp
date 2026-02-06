#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int board_num[2001];
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> board_num[i];
    }
    cin >> M;

    
    // base case
    for (int i = 1; i <= N; i++) dp[i][i] = true;

    // 길이가 2일 때
    for (int i = 1; i <= N; i++) {
        if (board_num[i] == board_num[i+1]) dp[i][i+1] = true;
    }
    
    // 길이가 3이상일 때
    for (int len = 3; len <= N; len++)
    {
        for (int S = 1; S <= N-len+1; S++)
        {
            int E = S + len - 1;
            if (board_num[S] == board_num[E] && dp[S+1][E-1]) {
                dp[S][E] = true;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }
    
    
    
    

    return 0;
}