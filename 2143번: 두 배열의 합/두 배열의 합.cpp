#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
long long T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    cin >> N;
    vector<int> A(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    vector<int> B(M+1, 0);
    for (int i = 1; i <= M; i++) cin >> B[i];

    vector<long long> subA, subB;

    for (int i = 1; i <= N; i++) {
        long long cur_sum = 0;
        for (int j = i; j <= N; j++) {
            cur_sum += A[j];
            subA.push_back(cur_sum);
        }
    }
    for (int i = 1; i <= M; i++) {
        long long cur_sum = 0;
        for (int j = i; j <= M; j++) {
            cur_sum += B[j];
            subB.push_back(cur_sum);
        }
    }
    sort(subB.begin(), subB.end());
    long long ans = 0;
    for (int i = 0; i < subA.size(); i++) {
        long long check_num = T - subA[i];
        long long cnt = upper_bound(subB.begin(), subB.end(), check_num) - lower_bound(subB.begin(), subB.end(), check_num);
        ans += cnt;
    }
    cout << ans;
    

    
    return 0;
}