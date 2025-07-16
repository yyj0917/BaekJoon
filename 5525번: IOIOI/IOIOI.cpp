#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string S;

    cin >> n >> m >> S;

    int cnt = 0;
    int ans = 0;

    for (int i = 1; i < m - 1;)
    {
       if (S[i-1] == 'I' && S[i] == 'O' && S[i+1] == 'I') {
            cnt++;
            if (cnt >= n) ans++;
            i += 2;
       } else {
            cnt = 0;
            i++;
       }
    }
    cout << ans << '\n';

    return 0;
}