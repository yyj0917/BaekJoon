#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int k, n;
        cin >> k >> n;
        int dp[15][15] = {};

        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= k; i++)
        {
            dp[i][1] = 1;
            for (int j = 2; j <= n; j++)
            {
               
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        cout << dp[k][n] << endl;
        
    }
    return 0;
    
}