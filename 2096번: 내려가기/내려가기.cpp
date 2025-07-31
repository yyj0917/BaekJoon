#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int max_dp[3] = {0};
    int min_dp[3] = {0};
    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int temp_max[3] = {
            max(max_dp[0], max_dp[1]) + a,
            max({max_dp[0], max_dp[1], max_dp[2]}) + b,
            max(max_dp[1], max_dp[2]) + c
        };
        
        int temp_min[3] = {
            min(min_dp[0], min_dp[1]) + a,
            min({min_dp[0], min_dp[1], min_dp[2]}) + b,
            min(min_dp[1], min_dp[2]) + c
        };
        
        for (int j = 0; j < 3; j++) {
            max_dp[j] = temp_max[j];
            min_dp[j] = temp_min[j];
        }
    }
    
    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << ' ' 
         << min({min_dp[0], min_dp[1], min_dp[2]}) << '\n';
    
    return 0;
}