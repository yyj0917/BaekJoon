#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<int> op(4); // 덧셈, 뺄셈, 곱셈, 나눗셈
vector<int> num;
int max_sum = -1e9;
int min_sum = 1e9;
void solve(int idx, int sum) {
    if (idx == N-1) {
        max_sum = max(max_sum, sum);
        min_sum = min(min_sum, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0) continue;
        op[i] -= 1;
        if (i == 0) {
            solve(idx+1, sum + num[idx+1]);
        } else if (i == 1) {
            solve(idx+1, sum - num[idx+1]);
        } else if (i == 2) {
            solve(idx+1, sum * num[idx+1]);
        } else {
            if (sum < 0) {
                int abs_sum = abs(sum);
                abs_sum /= num[idx+1];
                sum = -abs_sum;
            } else sum /= num[idx+1];
            solve(idx+1, sum);
        }
        op[i] += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        num.push_back(a);
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];
    
    solve(0, num[0]);
    cout << max_sum << "\n" << min_sum;

    return 0;
}