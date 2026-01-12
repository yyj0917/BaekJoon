#include <iostream>
using namespace std;

int n;
int arr[17][17];
int ans = 0;

void dfs(int r, int c, int dir) {
    if (r == n && c == n) {
        ans++;
        return;
    }
    
    // dir: 0=가로, 1=세로, 2=대각선
    
    // 가로 이동 (dir 0, 2에서 가능)
    if (dir != 1 && c + 1 <= n && arr[r][c+1] == 0) {
        dfs(r, c+1, 0);
    }
    
    // 세로 이동 (dir 1, 2에서 가능)
    if (dir != 0 && r + 1 <= n && arr[r+1][c] == 0) {
        dfs(r+1, c, 1);
    }
    
    // 대각선 이동 (모든 dir에서 가능)
    if (r + 1 <= n && c + 1 <= n && 
        arr[r][c+1] == 0 && arr[r+1][c] == 0 && arr[r+1][c+1] == 0) {
        dfs(r+1, c+1, 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(1, 2, 0);
    
    cout << ans << '\n';
    
    return 0;
}