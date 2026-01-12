#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int v, e;

int start;
vector<vector<int>> graph;

void solve(int start, int end, int dist) {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    cin >> start;

    graph.resize(v+1, vector<int>(v+1, -1));

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    vector<vector<int>> dist(v+1, vector<int> (v+1, -1));

    queue<int> q;
    q.push(start);
    graph[start][start] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (next != -1) {
                cout << next << '\n';
                
            }
        }
    }
    


    
    

    return 0;
}