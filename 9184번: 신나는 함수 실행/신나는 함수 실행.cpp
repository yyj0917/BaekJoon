#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int dp[21][21][21];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    for (int a = 0; a <= 20; a++)
        {
            for (int b = 0; b <= 20; b++)
            {
                for (int c = 0; c <= 20; c++)
                {
                    if (a == 0 || b == 0 || c == 0) 
                        dp[a][b][c] = 1;
                    else if (a < b && b < c) dp[a][b][c] =  dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
                    else dp[a][b][c] =  dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
                }
            }
        }
    while (true)
    {
        cin >> A >> B >> C;
        int res = 1;
        if (A == -1 && B == -1 && C == -1) break;
        if (A <= 0 || B <= 0 || C <= 0) {
            printf("w(%d, %d, %d) = %d\n", A, B, C, res);
            continue;
        }
        else if (A > 20 || B > 20 || C > 20) res = dp[20][20][20];
        else res = dp[A][B][C];
        printf("w(%d, %d, %d) = %d\n", A, B, C, res);

    }
    

    return 0;
}