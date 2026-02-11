#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;

void sort() {

}

vector<int> adj[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> indegree(N+1, 0);
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int tmp[num];
        for (int j = 0; j < num; j++)
        {
            cin >> tmp[j];
        }
        for (int j = 0; j < num-1; j++)
        {
            int u = tmp[j];
            int v = tmp[j+1];
            adj[u].push_back(v);
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (auto nxt : adj[cur]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    if (result.size() == N) 
        for (int a : result) cout << a << "\n";
    else cout << 0;
    
    
    

    

    return 0;
}