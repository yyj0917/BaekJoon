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
    for (int i = 0; i < n+1; i++) for (int j = 0; j < m+1; j++) dp[i][j] = 0;

    // 길이 먼저 구하기
    for (int i = 1; i <= n; i++)
    {
        for (int j= 1; j <= m; j++)
        {
            char a = str1[i-1];
            char b = str2[j-1];
            if (a == b) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    if (dp[n][m] > 0) {
        string result = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--; j--;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) i--;
                else j--;
            }
        }
        reverse(result.begin(), result.end()); // 뒤에서부터 찾았으므로 뒤집기
        cout << result;
    }
    
    

    return 0;
}