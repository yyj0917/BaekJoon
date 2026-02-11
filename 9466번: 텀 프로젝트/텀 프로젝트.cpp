#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int T;
vector<bool> visited(100001), finished(100001);
int cnt = 0;
void dfs(vector<int> &adj, int cur) {
    visited[cur] = true;

    int nxt = adj[cur]; // 각 학생은 한명만 지목
    if (!visited[nxt]) dfs(adj, nxt);
    else if (!finished[nxt]) {
        for (int i = nxt; i != cur; i = adj[i]) {
            cnt++;
        }
        cnt++; // 자기 자신 포함
    }
    finished[cur] = true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> adj(n+1);
        for (int i = 0; i <= n; i++)
        {
            visited[i] = finished[i] = false;
        }
        
        for (int i = 1; i <= n; i++)
        {
            int v;
            cin >> v;
            adj[i] = v;
        }
        for (int i = 1; i <= n; i++) {
            dfs(adj, i);
        }
        cout << n - cnt << "\n";
        cnt = 0;
        
    }
    

    return 0;
}