#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9;
int N, K;

vector<int> fast_time;
int ans = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    if (N == K) {
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }

    queue<int> q;
    vector<int> time(100001, INF);
    q.push(N);
    time[N] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (time[cur] > time[K]) continue;
        
        for (auto x : {cur-1, cur+1, cur*2}) {
            if (x < 0 || x > 100000) continue;
            if (x == K) {
                // 처음 도달
                if (time[K] == INF) {
                    time[K] = time[cur]+1;
                    ans = 1; // 왜 1로 초기화? -> 최소시간을 경신할 때(처음 도달한 곳)
                } 
                // 이미 도달한 적이 있는데 똑같이 최소시간
                else if (time[K] == time[cur] + 1) {
                    ans++;
                }
            } else {
                if (time[x] >= time[cur]+1) { // 처음 방문하거나, 이미 방문했지만, 같은 시간대인 경우
                    time[x] = time[cur]+1;
                    q.push(x);
                }
            }
        }
    }
    for (int i = 0; i < fast_time.size(); i++)
    {
        if (time[K] == fast_time[i]) {
            ans++;
        }
    }
    cout << time[K] << "\n" << ans << "\n";
    
    return 0;
}