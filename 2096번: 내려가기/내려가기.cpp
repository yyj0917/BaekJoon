#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;
int n;
// vector<vector<int>> board;
struct Play {
    int first, second, third, min_first, min_second, min_third;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    // board.resize(n+1, vector<int> (3, 0));

    vector<Play> dp;
    dp.push_back({0, 0, 0, 0, 0, 0});
    

    for (int i = 0; i < n; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        int max_f, max_s, max_t, min_f, min_s, min_t;
        max_f = max(dp[0].first, dp[0].second) + first;
        max_s = max(dp[0].first, max(dp[0].second, dp[0].third)) + second;
        max_t = max(dp[0].second, dp[0].third) + third;
        min_f = min(dp[0].min_first, dp[0].min_second) + first;
        min_s = min(dp[0].min_first, min(dp[0].min_second, dp[0].min_third)) + second;
        min_t = min(dp[0].min_second, dp[0].min_third) + third;
        dp.pop_back();
        dp.push_back({max_f, max_s, max_t, min_f, min_s, min_t});
    }
    int max_score = 0, min_score = INT_MAX;
    max_score = max(max_score, dp[0].first);
    max_score = max(max_score, dp[0].second);
    max_score = max(max_score, dp[0].third);
    min_score = min(min_score, dp[0].min_first);
    min_score = min(min_score, dp[0].min_second);
    min_score = min(min_score, dp[0].min_third);
    cout << max_score << ' ' << min_score << '\n';


    // // max score
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + board[i][0];
    //     dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])) + board[i][1];
    //     dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + board[i][2];
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     max_score = max(max_score, dp[n][i]);
    // }
    // memset(dp, 0, sizeof(dp));
    // // min score
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + board[i][0];
    //     dp[i][1] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + board[i][1];
    //     dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + board[i][2];
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     min_score = min(min_score, dp[n][i]);
    // }
    // cout << max_score << " " << min_score << '\n';

    return 0;
}