#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    int left = 0, right = N - 1;
    // 두 용액의 합의 최솟값 저장 (최대 10억 + 10억 = 20억)
    long long min_diff = 2e9 + 7; 
    pair<int, int> ans;

    while (left < right) {
        int sum = v[left] + v[right];

        // 합의 절댓값이 이전 최솟값보다 작으면 갱신
        if (abs(sum) < min_diff) {
            min_diff = abs(sum);
            ans = {v[left], v[right]};
        }

        if (sum == 0) break; // 합의 값이 0이면 스탑

        // 합이 0보다 크면? 줄여야 하고, 0보다 작으면 키워야 함.
        if (sum > 0) right--;
        else left++;
    }
    cout << ans.first << " " << ans.second;
    
    

    return 0;
}