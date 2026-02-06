#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 전역 변수 설정
int N, M, ans = 0;
int origin_map[9][9];
int temp_map[9][9];

// 상하좌우 이동을 위한 방향 배열
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 1. 바이러스 전파 (BFS)
void bfs(const vector<pair<int, int>>& virus_pos) {
    queue<pair<int, int>> q;
    
    // 모든 바이러스 시작점을 큐에 삽입
    for (auto v : virus_pos) q.push(v);

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 맵 범위 내에 있고 빈칸(0)인 경우에만 바이러스 전파
            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M) {
                if (temp_map[nr][nc] == 0) {
                    temp_map[nr][nc] = 2; // 바이러스 감염
                    q.push({nr, nc});
                }
            }
        }
    }
}

// 2. 안전 영역 크기 계산
int count_safe_area() {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (temp_map[i][j] == 0) count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<pair<int, int>> virus_pos;
    vector<pair<int, int>> empty_spaces;

    // 맵 정보 입력 및 좌표 분류
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> origin_map[i][j];
            if (origin_map[i][j] == 2) virus_pos.push_back({i, j});
            else if (origin_map[i][j] == 0) empty_spaces.push_back({i, j});
        }
    }

    // 3. 모든 빈칸 중 3개를 고르는 브루트포스 (조합)
    int total_empty = empty_spaces.size();
    for (int i = 0; i < total_empty - 2; i++) {
        for (int j = i + 1; j < total_empty - 1; j++) {
            for (int k = j + 1; k < total_empty; k++) {
                
                // [벽 세우기] 임시로 원본 맵에 벽 3개 설치
                origin_map[empty_spaces[i].first][empty_spaces[i].second] = 1;
                origin_map[empty_spaces[j].first][empty_spaces[j].second] = 1;
                origin_map[empty_spaces[k].first][empty_spaces[k].second] = 1;

                // [맵 복사] 바이러스가 퍼질 도화지(temp_map) 준비
                for (int r = 1; r <= N; r++) {
                    for (int c = 1; c <= M; c++) temp_map[r][c] = origin_map[r][c];
                }

                // [바이러스 전파]
                bfs(virus_pos);

                // [결과 갱신] 안전 영역 최댓값 업데이트
                ans = max(ans, count_safe_area());

                // [벽 허물기] 다음 조합을 위해 원상복구
                origin_map[empty_spaces[i].first][empty_spaces[i].second] = 0;
                origin_map[empty_spaces[j].first][empty_spaces[j].second] = 0;
                origin_map[empty_spaces[k].first][empty_spaces[k].second] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}