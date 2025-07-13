#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt = 0;

void dfs (int x, int y, vector<vector<int>> &adj, vector<vector<bool>> &visited) {
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (adj[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, adj, visited);
            }
        }
    }
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> adj(n+1, vector<int> (n+1, 0));
    vector<vector<bool>> visited(n+1, vector<bool> (n+1, false));
    vector<int> apart;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            adj[i][j] = str[j] - '0';
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, adj, visited);
                apart.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << apart.size() << '\n';
    sort(apart.begin(), apart.end());
    for (int num : apart)
    {
        cout << num << '\n';
    }
    
    


    return 0;
}