#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends(n+1);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    

    int min_bacon = INT_MAX, min_user = 0;
    for (int start = 1; start <= n; start++)
    {
        int bacon_cnt = 0;
        vector<int> checked(n+1, -1);
        queue<int> q;
        q.push(start);
        checked[start] = 0;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next : friends[cur]) {
                if (checked[next] == -1) {
                    checked[next] = checked[cur] + 1;
                    q.push(next);
                }
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += checked[i];
        }
        
        if (sum < min_bacon) {
            min_bacon = sum;
            min_user = start;
        }
    }
    cout << min_user;
    
    

    return 0;
}