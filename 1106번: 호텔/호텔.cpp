#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
int C, N;

int dp[1105]; // 고객 i명을 모으는데 필요한 최소 비용 dp배열
vector<pair<int, int>> cities;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> C >> N;
    fill(dp, dp + C + 101, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int cost, city;
        cin >> cost >> city;
        cities.push_back({cost, city});
    }
    for (int i = 0; i < N; i++)
    {
        int cost = cities[i].first;
        int gain_customer = cities[i].second;

        for (int j = gain_customer; j <= C + 100; j++)
        {
            if (dp[j - gain_customer] != INF) {
                dp[j] = min(dp[j], dp[j - gain_customer] + cost);
            }
        }
    }
    int ans = INF;
    for (int i = C; i <= C + 100; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans;
    
    
    

    return 0;
}