#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.length();
    int m = str2.length();
    int dp[n+1][m+1];
    string ans[n+1][m+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            dp[i][j] = 0;
            ans[i][j] = "";
        }
        
    }
    string ans1 = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j= 1; j <= m; j++)
        {
            char a = str1[i-1];
            char b = str2[j-1];
            if (a == b) {
                dp[i][j] = dp[i-1][j-1] + 1;
                ans[i][j] = ans[i-1][j-1] + a;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    ans[i][j] = ans[i-1][j];
                } else {
                    ans[i][j] = ans[i][j-1];
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int max_len = dp[n][m];
    string max_len_str = ans[n][m];
    
    if (max_len > 0) {
        cout << max_len << "\n" << max_len_str;
    } else {
        cout << max_len;
    }
    
    

    return 0;
}