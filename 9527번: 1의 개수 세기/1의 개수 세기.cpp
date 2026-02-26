#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long A, B;
long long dp[56];


long long solve(long long x) {
    if (x <= 0) return 0; // 0 이하일 때는 1이 없음    
    vector<int> v;
    long long tmp = x;
    while (tmp != 0) {
        v.push_back(tmp % 2);
        tmp /= 2;
    }
    long long ans = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == 1) {
            ans += dp[i] + x - ((long long)1<<i) + 1;
            x -= (1LL<<i);
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    dp[0] = 0;
    for (int i = 1; i <= 55; i++)
    {
        dp[i] = 2 * dp[i-1] + 1LL << (i-1);
    }

    cout << solve(B) - solve(A-1);


    return 0;
}