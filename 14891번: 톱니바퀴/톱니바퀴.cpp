#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

void rotate(int dir, deque<int>& dq) {
    // 시계방향
    if (dir == 1) {
        int back = dq.back();
        dq.push_front(back);
        dq.pop_back();
    } 
    // 반시계방향
    else {
        int front = dq.front();
        dq.push_back(front);
        dq.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> gear[4];
    for (int i = 0; i < 4; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++)
        {
            gear[i].push_back(str[j]- '0');
        }
    }
    int K;
    cin >> K;
    while (K--)
    {
        int k, dir;
        cin >> k >> dir;
        k -= 1;
        int rot[4] = {0}; // 0 : 안 돌기, 1 : 시계, -1 : 반시계

        rot[k] = dir;
        // 왼쪽 전파
        for (int i = k; i > 0; i--)
        {
            if (gear[i][6] != gear[i-1][2]) {
                rot[i-1] = -rot[i];
            } else break;
        }
        // 오른쪽 전파
        for (int i = k; i < 3; i++)
        {
            if (gear[i][2] != gear[i+1][6]) {
                rot[i+1] = -rot[i];
            } else break;
        }
        // 회전 적용
        for (int i = 0; i < 4; i++)
        {
            if (rot[i] != 0) {
                rotate(rot[i], gear[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans += gear[i].front() * (1 << i);
    }
    cout << ans;

    return 0;
}