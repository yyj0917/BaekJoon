#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int N, M, K;
vector<int> map[51][51];

struct FireBall {
    int r, c, m, s, d;
    bool isCheck = true;
};
vector<FireBall> fb;

pair<int, int> dir_move(int d) {
    int dr = 0, dc = 0;
    if (d == 0) dr = -1; 
    else if (d == 1) {dr = -1; dc = 1;}
    else if (d == 2) dc = 1;
    else if (d == 3) {dr = 1; dc = 1;}
    else if (d == 4) dr = 1;
    else if (d == 5) {dr = 1; dc = -1;}
    else if (d == 6) dc = -1;
    else {dr = -1; dc = -1;}
    return {dr, dc};
}

void fb_move() {
    for (int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        map[i][j].clear();
    for (int i = 0; i < fb.size(); i++)
    {
        if (!fb[i].isCheck) continue;
        int dir = fb[i].d;
        pair<int, int> p = dir_move(dir);
        int dr = p.first; int dc = p.second;
        int move = fb[i].s % N;
        fb[i].r = ( (fb[i].r - 1 + dr*move) % N + N ) % N + 1;
        fb[i].c = ( (fb[i].c - 1 + dc*move) % N + N ) % N + 1;
        map[fb[i].r][fb[i].c].push_back(i);
    }
}
void fb_divide() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j].size() > 1) {
                int sum_m=0, sum_s=0, fb_size = map[i][j].size();
                bool allEven = true, allOdd = true;
                for (int k = 0; k < fb_size; k++)
                {
                    sum_m += fb[map[i][j][k]].m;
                    sum_s += fb[map[i][j][k]].s;
                    int d = fb[map[i][j][k]].d;
                    if (d % 2 == 0) allOdd = false;
                    else allEven = false;
                    fb[map[i][j][k]].isCheck = false;
                }
                int div_m = sum_m / 5;
                if (div_m == 0) continue;
                int div_s = sum_s / fb_size;
                if (allEven || allOdd) { // 방향이 모두 홀수
                    fb.push_back({i, j, div_m, div_s, 0});
                    fb.push_back({i, j, div_m, div_s, 2});
                    fb.push_back({i, j, div_m, div_s, 4});
                    fb.push_back({i, j, div_m, div_s, 6});
                }  else {
                    fb.push_back({i, j, div_m, div_s, 1});
                    fb.push_back({i, j, div_m, div_s, 3});
                    fb.push_back({i, j, div_m, div_s, 5});
                    fb.push_back({i, j, div_m, div_s, 7});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;


    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fb.push_back({r,c,m,s,d});
    }

    while (K--)
    {
        fb_move();
        fb_divide();
    }
    int ans_m = 0;
    for (int i = 0; i < fb.size(); i++)
    {
        if (!fb[i].isCheck) continue;
        ans_m += fb[i].m;
    }
    
    cout << ans_m;
    

    
    return 0;
}