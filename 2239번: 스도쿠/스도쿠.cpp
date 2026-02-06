#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int board[10][10];
vector<pair<int, int>> blanks;
bool found = false;
// 같은 행에 겹치는 게 있는지
// 같은 열에 겹치는 게 있는지
// 같은 3x3 사각형 안에서 겹치는 게 없는지
// 'th'은 9개 중에 어떤 사각형인지
bool isValid(int r, int c, int num) {
    for (int i = 1; i <= 9; i++) {
        if (board[r][i] == num || board[i][c] == num) return false;
    }
    int sr = ((r - 1) / 3) * 3 + 1;
    int sc = ((c - 1) / 3) * 3 + 1;
    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == num) return false;
        }
    }
    return true;
}
void solve(int idx) {
    if (found) return; // 들어갈 수를 찾았다면 종료
    if (idx == blanks.size()) {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        found = true;
        return;
    }

    int r = blanks[idx].first;
    int c = blanks[idx].second;

    for (int k = 1; k <= 9; k++)
    {
        if (isValid(r, c, k)) {
            board[r][c] = k;
            solve(idx + 1); // 다음 빈칸으로
            board[r][c] = 0; // 백트래킹으로 원상복구하고, 다시 가능한 수로 다시 확인
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 9; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= 9; j++)
        {
            int num = str[j-1] - '0';
            board[i][j] = num;
            if (num == 0) {
                blanks.push_back({i, j});
            }
        }
    }
    solve(0);
    
    

    return 0;
}