#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool isPal[2501][2501];
int dp[2501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int len = str.length();

    // base case len = 1
    for (int i = 0; i < len; i++) isPal[i][i] = true;

    // base case len = 2
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == str[i+1]) isPal[i][i+1] = true;
    }

    // len 3 이상일 때
    for (int arr_len = 3; arr_len <= len; arr_len++) {
        for (int i = 0; i <= len - arr_len; i++) {
            int j = i + arr_len - 1; // 끝점
            if (str[i] == str[j] && isPal[i+1][j-1]) 
                isPal[i][j] = true;
        }
    }

    for (int i = 0; i < len; i++) {
        dp[i] = 1e9;
    }

    dp[0] = 1;
    // i번째문자까지의 부분 문자열을 반환했을 때 팰린드롬 분할 최소 개수
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (isPal[j][i]) {
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }
    
    cout << dp[len-1];
    


    return 0;
}