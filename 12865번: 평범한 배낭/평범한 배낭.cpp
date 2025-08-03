#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int n, k;
vector<int> weight;
vector<int> value;
int ans = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }
    int dp[n+1][k+1];
    for (int i = 0; i <= k; i++)
    {
        dp[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= k; w++)
        {
            dp[i][w] = dp[i-1][w]; // 선택 안 함
            if (w >= weight[i-1]) {
                dp[i][w] = max(dp[i][w], dp[i-1][w-weight[i-1]] + value[i-1]);
            } // 선택함
        }
    }
        
    
    
    cout << dp[n][k] << '\n';

    return 0;
}