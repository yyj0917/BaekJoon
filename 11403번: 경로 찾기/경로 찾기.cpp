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

    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<vector<bool>> visited(n+1, vector<bool> (n+1, false));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1) adj[i].push_back(j);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                if (!visited[i][next]) {
                    visited[i][next] = true;
                    q.push(next);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j]) cout << 1;
            else cout << 0;

            if (j != n) cout << ' ';
        }
        cout << '\n';
    }
    
    

    return 0;
}