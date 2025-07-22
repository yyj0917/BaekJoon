#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int tetromino[500][500];
int visited[500][500];
int ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int row, int col, int depth, int sum) {
    if (depth == 3) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nR = row + dy[i];
        int nC = col + dx[i];

        if (0 <= nC && nC < m && 0 <= nR && nR < n) {
            if (!visited[nR][nC]) {
                visited[nR][nC] = true;
                dfs(nR, nC, depth + 1, sum + tetromino[nR][nC]);
                visited[nR][nC] = false;
            }
        }
    }
}

// 예외 모양 ㅜ
void shape1(int r, int c) {
    int sum = 0;
    sum = tetromino[r][c] + tetromino[r][c+1] + tetromino[r][c+2] + tetromino[r+1][c+1];
    ans = max(ans, sum);
}
// 예외 모양 ㅗ
void shape2(int r, int c) {
    int sum = 0;
    sum = tetromino[r][c] + tetromino[r][c+1] + tetromino[r][c+2] + tetromino[r-1][c+1];
    ans = max(ans, sum);
}
// 예외 모양 ㅏ
void shape3(int r, int c) {
    int sum = 0;
    sum = tetromino[r][c] + tetromino[r+1][c] + tetromino[r+2][c] + tetromino[r+1][c+1];
    ans = max(ans, sum);
}
// 예외 모양 ㅓ
void shape4(int r, int c) {
    int sum = 0;
    sum = tetromino[r][c] + tetromino[r+1][c] + tetromino[r+2][c] + tetromino[r+1][c-1];
    ans = max(ans, sum);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tetromino[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 0, tetromino[i][j]);
            visited[i][j] = false;
            // shape 1 - ㅜ
            if (i + 1 < n && j + 2 < m) shape1(i, j);
            // shape 2 - ㅗ
            if (i - 1 >= 0 && j + 2 < m) shape2(i, j);
            // shape 3 - ㅏ
            if (i + 2 < n && j + 1 < m) shape3(i, j);
            // shape 4 - ㅓ
            if (i + 2 < n && j - 1 >= 0) shape4(i, j);
        }
    }
    cout << ans << endl;
    

    return 0;
}