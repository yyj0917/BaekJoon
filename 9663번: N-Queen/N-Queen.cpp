#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int ans = 0;
int N;
int col[15]; // col[row] = col -> col[3] = 4 -> queen은 3행 4열

// 내가 지금 row행에 퀸을 하나 놨는데, 0번부터 row-1번 행까지 이미 앉아있는 선배 퀸들 중에 나랑 같은 열이거나 대각선에 있는 사람이 한 명이라도 있니?하는 함수
bool isPossible(int row) {
    for (int i = 0; i < row; i++)
    {
        if (col[row] == col[i]) return false; // 이미 선배 퀸이 같은 열에 있는 게 아닌지 확인
        else {
            if (abs(row - i) == abs(col[row] - col[i])) return false;
            // 대각선에 있어 -> |행의 차이| == |열의 차이|
        }
    }
    return true;
}

// 재귀적으로 행을 탐색
void recursiveSearchRow(int row) {

    if (row == N) {
        ans++;
        return; // 총 N개의 퀸을 다 놨으면 경우의 수 +1
    }
    // 현재 행(row)에서 모든 열(i)을 하나씩 시도
    for (int i = 0; i < N; i++) {
        col[row] = i; // 현재 행의 i번째 열에 퀸을 배치

        if (isPossible(row)) { // 이 위치가 괜찮다면
            recursiveSearchRow(row + 1); // 다음 행으로 진행 (Recursive Call)
        }
        // 만약 안 괜찮다면? for문의 다음 i(열)로 넘어가며 자연스럽게 백트래킹!
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    recursiveSearchRow(0);
    cout << ans << "\n";
    
    return 0;
}