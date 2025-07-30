#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int n;
int ans = 0;
int result = INT_MAX;
int rgb[1001][1001];

void draw(int homeNum, int colorIdx) {
    if (homeNum > n) {
        // cout << "ans: " << ans << endl;
        result = min(result, ans);
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (i != colorIdx) {
            ans += rgb[homeNum][i];
            draw(homeNum + 1, i);
            ans -= rgb[homeNum][i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    // 순서대로 red, green, blue;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> rgb[i][j];
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        ans += rgb[1][i];
        draw(2, i);
        ans -= rgb[1][i];
    }
    cout << result << '\n';
    

    return 0;
}