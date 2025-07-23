#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int n, m;
void sol(int start, int depth, vector<int>& cur, vector<vector<int>>& ans) {
    if (depth == m) {
        ans.push_back(cur);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        cur.push_back(i);
        sol(i, depth+1, cur, ans);
        cur.pop_back();
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<int> cur;
    vector<vector<int>> ans;
    

    if (m == 1) {
        for (int i = 1; i <= n; i++)
        {
            cout << i << '\n';
        }
    } else {
        sol(1, 0, cur, ans);
    }

    for (const auto& comb : ans) {
        for (int i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size()-1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}