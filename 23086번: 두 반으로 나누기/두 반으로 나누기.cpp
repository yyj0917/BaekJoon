#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;

vector<pair<int, int>> edges(200000);
vector<int> adj[200000];
int broken_order[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    
    for (int i = 1; i <= K; i++)
    {
        int e; cin >> e;
        broken_order[e] = i;
    }

    int low = 0, high = K;
    int result = -1;
    int class_1 = 0, class_2 = 0;
    vector<int> color(N+1, 0); // 1 : white, 2 : black

    while (low <= high)
    {
        int mid = (low+high)/2;
        // broken된 그래프
        for (int i = 1; i <= N; i++)
        {
           adj[i].clear();
           color[i] = 0;
        }
        
        for (int i = 1; i <= M; i++)
        {
            // 만약 i번 간선이 mid 이전에 부서졌다면 (1 <= broken_order[i] <= mid)
            if (broken_order[i] > 0 && broken_order[i] <= mid) continue;

            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool ans = true;
        for (int i = 1; i <= N; i++)
        {
            if (color[i] == 0) {
                if (!ans) break;
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int cur = q.front(); q.pop();
                    for (int nxt : adj[cur]) {
                        if (!color[nxt]) {
                            color[nxt] = 3 - color[cur];
                            q.push(nxt);
                        } else if (color[nxt] == color[cur]) {
                            ans = false;
                            break;
                        }
                    }
                    if (!ans) break;
                }
            }
        }
        
        if (ans) {
            result = mid;
            int temp_c1 = 0, temp_c2 = 0;
            for (int i = 1; i <= N; i++) {
                if (color[i] == 1) temp_c1++;
                else temp_c2++;
            }
            class_1 = temp_c1;
            class_2 = temp_c2;
            high = mid-1;
        }
        else low = mid + 1;
    }
    
    if (result == -1) {
        cout << result << endl;
    } else {
        cout << result << "\n";
        cout << min(class_1, class_2) << " " << max(class_1, class_2) << "\n";
    }
    
    return 0;
}