#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a[9] = {4,2,3,5,1,8,13,21,34};

    int n = 9;
    int bestLen = 1;
    pair<int, int> bestPair = {1, 1};

    int dp[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = 2;
        }
        
    }
    

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= j-1; i++)
        {
            dp[i][j] = 2;
            for (int h = 1; h <= i - 1; h++)
            {
                if ((a[h] + a[i] <= a[j]) && dp[h][i] + 1 > dp[i][j]) {
                    dp[i][j] = dp[h][i] + 1;
                }
            }
            if (dp[i][j] > bestLen) {
                bestLen = dp[i][j];
                bestPair = {i, j};
            }
        }
    }
    
    cout << "result : " << dp[bestPair.first][bestPair.second] << endl;

    return 0;
}