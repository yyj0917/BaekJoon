#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> num(n+1);
    vector<long long> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + num[i];
    }
    

    while(m--) {
        int sum = 0;

        int a, b;
        cin >> a >> b;
        sum = dp[b] - dp[a-1];
        cout << sum << "\n";
    }
    
    return 0;
}