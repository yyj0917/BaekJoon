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

    vector<int> score(n+1);

    for (int i = 1; i < n+1; i++)
    {
        cin >> score[i];
    }
    
    vector<int> dp(n+1, 0);
    dp[1] = score[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }   
    
    cout << dp[n] << endl;
    return 0;
}