#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char board[10][10];
bool visited[10][10][10][10];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// 0-based
struct State {
    int ry, rx; // 빨간 구슬 좌표
    int by, bx; // 파란 구슬 좌표
    int depth;  // 현재 몇 번 기울였는지
};
// 결과물: {최종y, 최종x, 이동거리, 구멍에빠졌나}
struct Result {
    int y, x, dist;
    bool inHole;
};
Result move(int y, int x, int dy, int dx) {
    int d = 0;
    bool hole = false;
    
    // 다음 칸이 벽이 아니고, 현재 칸이 구멍이 아닐 때까지 전진
    while (board[y + dy][x + dx] != '#' && board[y][x] != 'O') {
        y += dy;
        x += dx;
        d++;
        if (board[y][x] == 'O') {
            hole = true;
            break;
        }
    }
    return {y, x, d, hole};
}
int move_all(State obj) {
    queue<State> q;
    q.push({obj.ry, obj.rx, obj.by, obj.bx, 0});
    visited[obj.ry][obj.rx][obj.by][obj.bx] = true; // 시작점 방문 처리
    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        if (curr.depth >= 10) continue;
        for (int i = 0; i < 4; i++)
        {
            int d_y = dy[i];
            int d_x = dx[i];
            // 1. 일단 각각 굴린다
            Result nextR = move(curr.ry, curr.rx, d_y, d_x);
            Result nextB = move(curr.by, curr.bx, d_y, d_x);

            // 2. 파란 구슬이 빠졌으면 이 경로는 무조건 탈락! (빨간 구슬과 동시에 빠져도 안 됨)
            if (nextB.inHole) continue; 

            // 3. 빨간 구슬만 빠졌으면 성공!
            if (nextR.inHole) return curr.depth + 1;

            // 4. 둘 다 안 빠졌는데 위치가 같다면?
            if (nextR.y == nextB.y && nextR.x == nextB.x) {
                // 더 많이 움직인 놈이 더 뒤에서 출발했다는 뜻
                if (nextR.dist > nextB.dist) {
                    nextR.y -= d_y; nextR.x -= d_x; // 빨간 구슬 한 칸 뒤로
                } else {
                    nextB.y -= d_y; nextB.x -= d_x; // 파란 구슬 한 칸 뒤로
                }
            }
            if (!visited[nextR.y][nextR.x][nextB.y][nextB.x]) {
                visited[nextR.y][nextR.x][nextB.y][nextB.x] = true;
                q.push({nextR.y, nextR.x, nextB.y, nextB.x, curr.depth+1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    State obj;

    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < M; j++)
        {
            if (str[j] == 'R') {
                obj.ry = i;
                obj.rx = j;
            }
            else if (str[j] == 'B') {
                obj.by = i;
                obj.bx = j;
            }

            board[i][j] = str[j];
        }
    }
    int ans = move_all(obj);
    cout << ans;
    
    

    return 0;
}