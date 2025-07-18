#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin >> m >> n;

    vector<vector<int>> tomato(n);
    vector<vector<bool>> ripened(n, vector<bool> (m, false));

    vector<pair<int, int>> ripened_tomato;
    int unripened = 0, not_tomato = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if (x == 1) {
                ripened_tomato.push_back({i, j});
            } else if (x == 0) {
                unripened++;
            }
            tomato[i].push_back(x);
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < ripened_tomato.size(); i++)
    {
        int y = ripened_tomato[i].first;
        int x = ripened_tomato[i].second;
        ripened[y][x] = true;
        q.push({y, x});
    }
    

    int ans = -1;

    while (!q.empty())
    {
        ans++;
        if (unripened == 0) break;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int cur_x = q.front().second;
            int cur_y = q.front().first;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    if (tomato[ny][nx] == 0 && !ripened[ny][nx]) {
                        ripened[ny][nx] = true;
                        unripened--;
                        q.push({ny, nx});
                    }
                }
            }
        }
        

    }
    if (unripened == 0) cout << ans << '\n';
    else cout << -1 << '\n';
    

    return 0;
}