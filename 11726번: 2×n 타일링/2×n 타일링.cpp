#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(1001);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 1000; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1])%10007;
    }
    

    cout << dp[n] << endl;

    return 0;
}