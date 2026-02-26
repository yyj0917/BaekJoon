#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

bool checked[9];
vector<int> result;
void solve(int num, int cnt) {
    // checked[num] = true;

    if (cnt > M) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!checked[i]) {
            result.push_back(i);
            checked[i] = true;
            solve(i, cnt+1);
            checked[i] = false;
            result.pop_back();
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    solve(1, 1);
    return 0;
}