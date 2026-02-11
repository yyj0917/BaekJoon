#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int visited[1001][1001];
int safe_zones = 0;
char board[1001][1001];

void dfs(int r, int c) {
    visited[r][c] = 1;
    

    int nr = r, nc = c;
    if (board[r][c] == 'U') nr--;
    else if (board[r][c] == 'D') nr++;
    else if (board[r][c] == 'L') nc--;
    else if (board[r][c] == 'R') nc++;

    if (visited[nr][nc] == 0) {
        dfs(nr, nc);
    }
    else if (visited[nr][nc] == 1) { // 방문했던 노드를 만나면 새로운 사이클 발견 !
        safe_zones++;
    }
    visited[r][c] = 2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    cout << safe_zones;
    
    return 0;
}