#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int R, C;
char board[21][21];
vector<char> checkBoard;
int max_dist = 1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<int>> &dist) {
    for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (1 <= nx && nx <= C && 1 <= ny && ny <= R) {
                bool isCheck = true;
                for (char c : checkBoard) {
                    if (board[ny][nx] == c) isCheck = false;
                }
                if (isCheck == true) {
                    dist[ny][nx] = dist[y][x] + 1;
                    max_dist = max(max_dist, dist[ny][nx]);
                    // cout << "ny : " << ny << " nx : " << nx << " dist ny nx : " << dist[ny][nx] << '\n';
                    checkBoard.push_back(board[ny][nx]);
                    dfs(nx, ny, dist);
                    checkBoard.pop_back();
                }
                
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(21, vector<int>(21, 0));
            
    dist[1][1] = 1;
    checkBoard.push_back(board[1][1]);

    dfs(1, 1, dist);

    // for (int i = 1; i <= R; i++)
    // {
    //     for (int j = 1; j <= C; j++)
    //     {
    //         cout <<"i: " << i << " j : " << j <<  " dist[i][j] : " << dist[i][j] << '\n';
    //         max_dist = max(max_dist, dist[i][j]);
    //     }
    // }
    
    cout << max_dist << '\n';

    return 0;
}