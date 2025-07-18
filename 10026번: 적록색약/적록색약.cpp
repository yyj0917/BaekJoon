#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
vector<vector<bool>> weaked_checked;
vector<vector<bool>> checked;

void weaked_dfs(int row, int col, vector<string> &colorGrid, char color) {
    weaked_checked[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = col + dx[i];
        int ny = row + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (color == 'R' || color == 'G') {
                if ((colorGrid[ny][nx] == 'R' || colorGrid[ny][nx] == 'G') && !weaked_checked[ny][nx]) {
                    weaked_dfs(ny, nx, colorGrid, color);
                }
            } else {
                if (colorGrid[ny][nx] == color && !weaked_checked[ny][nx]) {
                    weaked_dfs(ny, nx, colorGrid, color);
                }
            }

        }
    }
    
}
void dfs(int row, int col, vector<string> &colorGrid, char color) {
    checked[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = col + dx[i];
        int ny = row + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if ((colorGrid[ny][nx] == color) && !checked[ny][nx]) {
                dfs(ny, nx, colorGrid, color);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<string> colorGrid(n);
    weaked_checked.resize(n, vector<bool> (n, false));
    checked.resize(n, vector<bool> (n, false));


    int weaked_bound = 0;
    int bound = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> colorGrid[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!weaked_checked[i][j]) {
                weaked_dfs(i, j, colorGrid, colorGrid[i][j]);
                weaked_bound++;
            }
            if (!checked[i][j]) {
                dfs(i, j, colorGrid, colorGrid[i][j]);
                bound++;
            }
        }
    }

    cout << bound << " " << weaked_bound << '\n';
    
    
    return 0;
}