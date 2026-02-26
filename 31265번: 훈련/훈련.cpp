#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
bool dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> train_cnt; // i번째 훈련상황에서의 훈련 개수

    for (int i = 0; i < N; i++) {
        int cnt;
        cin >> cnt;
        train_cnt.push_back(cnt);
    }

    // train_time[i][j] => i번째 훈련상황에서 j번째 훈련이 걸리는 시간
    vector<vector<int>> train_time(N+1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < train_cnt[i]; j++) {
            int time;
            cin >> time;
            train_time[i].push_back(time);
        }
    }
    
    dp[0] = true;

    for (int i = 0; i < N; i++) {
        
        bool next_dp[10001];
        memset(next_dp, false, sizeof(next_dp));
        
        for (int t : train_time[i]) {
            for (int j = M - t; j >= 0; j--) {
                if (dp[j] || next_dp[j]) {
                    next_dp[j + t] = true;
                }
            }
        }
        memcpy(dp, next_dp, sizeof(dp));
    }

    int result = -1;
    for (int i = M; i >= 0; i--)
    {
        if (dp[i]) {
            result = i;
            break;
        }
    }
    cout << result;
    
    


    return 0;
}