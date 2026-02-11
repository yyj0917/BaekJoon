#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n;

vector<long long> A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    A.resize(n+1);
    B.resize(n+1);
    C.resize(n+1);
    D.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // A + B & C + D의 모든 경우의 수
    vector<int> result_A_B, result_C_D;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_A_B.push_back(A[i] + B[j]);
            result_C_D.push_back(C[i] + D[j]);
        }
    }
    
    
    // 투 포인터를 위한 정렬
    sort(result_A_B.begin(), result_A_B.end());
    sort(result_C_D.begin(), result_C_D.end());
// for (int i = 0; i < result_A_B.size(); i++)
//     {
//         cout << result_A_B[i] << " " << result_C_D[result_A_B.size()-1-i] << endl;
//     }
    // 모든 경우의 수
    long long ans = 0;
    int size = result_A_B.size();
    int left = 0, right = result_A_B.size()-1;

    // result_A_B의 left(음수) + result_C_D의 right(양수)
    while (left < size && right >= 0) {
        int sum = result_A_B[left] + result_C_D[right];
        if (sum == 0) {
            long long target_left = result_A_B[left];
            long long cnt_left = 0;
            // result_A_B에서 같은 값의 개수 세기
            while (left < result_A_B.size() && result_A_B[left] == target_left) {
                cnt_left++;
                left++;
            }

            long long target_right = result_C_D[right];
            long long cnt_right = 0;
            // result_C_D에서 같은 값의 개수 세기
            while (right >= 0 && result_C_D[right] == target_right) {
                cnt_right++;
                right--;
            }

            ans += (cnt_left * cnt_right);

        } 
        else if (sum > 0) right--;
        else left++;
    }
    cout << ans;
    return 0;
}