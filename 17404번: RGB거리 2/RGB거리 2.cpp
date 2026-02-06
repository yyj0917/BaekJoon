#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct Cost {
    int r, g, b;
};

int N;

int house[1005][3]; // 0 : r, 1 : g, 2 : b
int min_cost = 1e9;

int dp[1005][3];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int r, g, b;
        cin >> r >> g >> b;
        house[i][0] = r;
        house[i][1] = g;
        house[i][2] = b;
    }
    
    for (int start_color = 0; start_color < 3; start_color++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == start_color) {
                dp[1][j] = house[1][j];
            } else {
                dp[1][j] = 1e9;
            }
        }
        // 2번째 집부터 N번째 집까지 채우기
            for (int j = 2; j <= N; j++)
            {
                dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + house[j][0];
                dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + house[j][1];
                dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + house[j][2];
            }

            // 첫번째 집과 N번째 집 비교하기
            for (int end_color = 0; end_color <= 2; end_color++)
            {
                if (start_color == end_color) continue;
                else {
                    min_cost = min(min_cost, dp[N][end_color]);
                }
            }
    }

    cout << min_cost;
    
    return 0;
}