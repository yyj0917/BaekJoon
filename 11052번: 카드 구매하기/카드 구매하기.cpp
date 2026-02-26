#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;
int P[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }

    dp[0] = 0;
    

    for (int i = 1; i <= N; i++) // 현재 내가 산 카드 개수
    {
       for (int j = 1; j <= i; j++) // 카드팩의 카드 개수 index
       {
            dp[i] = max(dp[i], dp[i-j] + P[j]);
       }
    }
    cout << dp[N];
    
    
    

    return 0;
}