#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int n, m;
vector<int> backtrack;
vector<bool> visited;
set<vector<int>> result;
vector<int> current;


void sol(int depth) {

    if (depth >= m) {
        result.insert(current);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            visited[i] = true;
            current.push_back(backtrack[i]);
            sol(depth + 1);
            current.pop_back();
            visited[i] = false;
        }
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    backtrack.resize(n, 0);
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> backtrack[i];
    }

    sort(backtrack.begin(), backtrack.end());

    sol(0);

    for (const auto &comp : result) {
        for (int num : comp) {
            cout << num << " ";
        }
        cout << '\n';
    }
    
    
    return 0;
}