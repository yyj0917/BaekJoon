#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> checked(100000 * 2 + 1, 0);

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        if (cur == k) break;
        q.pop();

        for (int i = 0; i < 3; i++)
        {
                if (i == 0) {
                    if (cur+1 <= 100000*2 && checked[cur+1] == 0) {
                        checked[cur+1] = checked[cur] + 1;
                        q.push(cur + 1);
                    }
                } else if (i == 1) {
                    if (cur-1 >= 0) {
                        if (checked[cur-1] == 0) {
                        checked[cur - 1] = checked[cur] + 1;
                        q.push(cur - 1);
                        }
                    }
                } else {
                    if (cur*2 <= 100000*2 && checked[cur*2] == 0) {
                        checked[cur * 2] = checked[cur] + 1;
                        q.push(cur * 2);
                    }
                }
        }
    }
    cout << checked[k] << '\n';

    return 0;
}