#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

long long a, b;
int ans = INT_MAX;

void solve(long long num, int depth) {
    if (num == b) {
        ans = min(ans, depth+1);
        return;
    }
    if (num > b) return;

    solve(num * 2, depth+1);
    solve(num * 10 + 1, depth+1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    solve(a, 0);
    if (ans == INT_MAX) ans = -1;
    
    cout << ans << '\n';

    return 0;
}