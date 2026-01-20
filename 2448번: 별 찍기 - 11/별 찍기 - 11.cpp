#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

char board[10000][10000];

void draw(int y, int x, int n) {
    // 1. [종료 조건] n이 3이 되면 (가장 작은 삼각형)
    //    -> 미리 정해둔 기본 패턴(별 5개짜리)을 (y, x) 위치에 하드코딩으로 박아넣습니다.
    if (n == 3) {
        board[y][x] = '*';
        board[y+1][x-1] = '*'; board[y+1][x+1] = '*';
        board[y+2][x-2] = '*'; board[y+2][x-1] = '*'; 
        board[y+2][x] = '*';   board[y+2][x+1] = '*'; board[y+2][x+2] = '*';
        return;
    }

    // 2. [재귀 호출] n이 3보다 크면 3등분으로 쪼갭니다.
    int half = n / 2;
    
    draw(y, x, half);           // 맨 위 삼각형 (꼭짓점 좌표 그대로)
    draw(y + half, x - half, half); // 왼쪽 아래 삼각형
    draw(y + half, x + half, half); // 오른쪽 아래 삼각형
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(board, ' ', sizeof(board));
    int n;
    cin >> n;

    draw(0, n-1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
    

    return 0;
}