#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
int cnt = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<char>> &adj, vector<vector<bool>> &visited) {
    visited[y][x] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (adj[ny][nx] != 'X' && !visited[ny][nx]) {
                if (adj[ny][nx] == 'P') cnt++;
                dfs(nx, ny, adj, visited);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pair<int, int> doyeon;

    vector<vector<char>> adj(n+1);
    vector<vector<bool>> visited(n+1, vector<bool> (m+1, false));

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] == 'I') {
                doyeon.first = j;
                doyeon.second = i;
            }
            adj[i].push_back(line[j]);
        }
    }

    dfs(doyeon.first, doyeon.second, adj, visited);
    if (cnt != 0) cout << cnt;
    else cout << "TT";
    
    return 0;
}