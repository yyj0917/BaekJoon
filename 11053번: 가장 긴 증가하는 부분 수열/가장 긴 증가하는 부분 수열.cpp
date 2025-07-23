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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int max_num = -1;
    for (int i = 0; i < n; i++)
    {
        max_num = max(max_num, dp[i]);
    }
    
    cout << max_num << '\n';
    
    return 0;
}