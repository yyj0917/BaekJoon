#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;
int max_block = -1;
// 한 줄을 왼쪽으로 미는 로직
vector<int> process(vector<int> row) {
    vector<int> next_row;
    // 0이 아닌 값 모으기
    int combine_pointer = -1;
    for (int i = 0; i < N; i++)
    {
        if (row[i] != 0) {
            if (next_row.empty()) {
                next_row.push_back(row[i]);
                continue;
            }
            int size = next_row.size()-1;
            if (combine_pointer != size && next_row[size] == row[i]) {
                next_row[size] *= 2;
                max_block = max(max_block, next_row[size]);
                combine_pointer = size;
            } else {
                next_row.push_back(row[i]);
            }
        }
    }
    for (int i = next_row.size(); i < N; i++) {
        next_row.push_back(0);
    }
    return next_row;
}
vector<vector<int>> rotate(vector<vector<int>>& map) {
    vector<vector<int>> copy_map(N, vector<int> (N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copy_map[N-j-1][i] = map[i][j];
        }
    }
    return copy_map;
}
void solve(vector<vector<int>> current_map, int move_cnt) {
    if (move_cnt > 5) return;

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> next_map = current_map;

        // 회전 (dir만큼 돌리기)
        for(int r = 0; r < dir; r++) {
            next_map = rotate(next_map); 
        }

        // 왼쪽으로 밀기
        for (int i = 0; i < N; i++) {
            next_map[i] = process(next_map[i]);
        }
        
        solve(next_map, move_cnt + 1);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<int>> map(N, vector<int> (N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            max_block = max(max_block, map[i][j]);
        }
    }

    solve(map, 1);
    
    cout << max_block;
    return 0;
}