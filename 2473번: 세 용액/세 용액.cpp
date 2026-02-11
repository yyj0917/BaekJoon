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

    vector<long long> V(N);

    for (int i = 0; i < N; i++) cin >> V[i];

    sort(V.begin(), V.end());


    long long ans[3];
    long long min_diff = 4e12;
    for (int i = 0; i < N; i++)
    {
        // 미리 하나를 골라놓고, 시작하기 -> ex) -2를 하나로 골라놓고, 투 포인터로 좁혀나갔을 때의 특정 조건을 -2로 잡는 것.
        int left = i+1, right = N-1;
        while (left < right)
        {

            long long sum = V[i] + V[left] + V[right];

            // 최솟값 갱신
            if (abs(sum) < min_diff) {
                min_diff = abs(sum);
                ans[0] = V[i];
                ans[1] = V[left];
                ans[2] = V[right];
            }
            if (sum > 0) right--;
            else if (sum < 0) left++;
            else {
                cout << ans[0] << " " << ans[1] << " " << ans[2];
                return 0;
            }
            
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
    
    return 0;
}