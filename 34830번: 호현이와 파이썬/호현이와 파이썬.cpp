#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long N, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    
    ans = (N * (N-1))/2;
    // N이 홀수일 때는 중복 간선이 필요없음 -> 그대로

    // N이 짝수일 때
    if (N % 2 == 0) {
        ans += (N - 2)/2;
    }
    cout << ans << endl;

    return 0;
}