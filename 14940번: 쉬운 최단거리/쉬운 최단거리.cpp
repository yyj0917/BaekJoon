#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> land(n);
    vector<vector<int>> dist(n, vector<int> (m, -1));

    int goal_x, goal_y;
    for (int i = 0; i < n; i++) // y
    {
       for (int j = 0; j < m; j++) // x
       {
            int t;
            cin >> t;
            if (t == 2) {
                goal_x = j;
                goal_y = i;
            }
            land[i].push_back(t);

       }
    }

    queue<pair<int,int>> q;
    q.push({goal_y, goal_x});
    dist[goal_y][goal_x] = 0;
    
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (land[ny][nx] == 1 && dist[ny][nx] == -1) {

                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 0) cout << 0; 
            else {
                if (dist[i][j] == -1) cout << -1;
                else {
                    cout << dist[i][j];
                }
            }
            if (j != m-1) cout << ' ';
        }
        cout << '\n';
    }
    


    

    return 0;
}