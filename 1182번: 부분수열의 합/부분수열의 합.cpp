#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, S;
vector<int> num;
int ans = 0;


void solve(int idx, int sum) {
    // cout << "idx : " << idx << " sum : " << sum << endl;
    // if (sum == S) 
    //     ans++;

    // for (int i = idx+1; i < N; i++)
    //     solve(i, sum + num[i]);
    if (idx == N) {
        if (sum == S) ans++;
        return;
    }

    // 현재 원소를 선택하지 않는 경우
    solve(idx + 1, sum);

    // 현재 원소를 선택한 경우
    solve(idx + 1, sum + num[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    
    
    // for (int i = 0; i < N; i++)
    // {
    //     solve(i, num[i]);
    // }
    solve(0, 0);

    if (S == 0) ans--;
    
    cout << ans;

    return 0;
}