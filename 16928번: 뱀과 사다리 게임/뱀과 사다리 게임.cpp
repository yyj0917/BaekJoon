#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int board[101][101];
int n, m;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    map<int, int> check;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u][0] = v;
        check[u] = v;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        board[u][0] = v;
        check[u] = v;
    }
    for (int i = 1; i < 101; i++)
    {
        for (int j = i; j < i + 6; j++)
        {
            if (!board[i][0]) {
                board[i][j] = j + 1;
            }
        }
    }
    vector<int> dist(101, -1);
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue;

            if (check[next]) next = check[next];  // 사다리나 뱀

            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    cout << dist[100] << endl;
    

    return 0;
}