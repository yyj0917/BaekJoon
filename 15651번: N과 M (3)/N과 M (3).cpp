#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int checked_num[8];
vector<int> result;

void solve(int cnt) {

    if (cnt == M) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
            result.push_back(i);
            solve(cnt+1);
            result.pop_back();
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    solve(0);
    return 0;
}