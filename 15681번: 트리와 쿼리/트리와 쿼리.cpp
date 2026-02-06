#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int disc[200000]; // i번째 트리를 몇번째로 방문했는지
int esc[200000]; // i번째 정점의 서브 트리의 검색을 끝났을 때의 esc 카운터
int cnt = -1; // 루트도 cnt를 하기 위해.
vector<int> adj[200000];
int N, R, Q;

void preorder(int cur, int parent) {
    disc[cur] = ++cnt; // 다른 노드를 방문했을 때 + 1
    for (auto next : adj[cur]) {
        if (next == parent) continue;
        preorder(next, cur);
    } // 자신의 서브트리를 방문하는 횟수를 세기 위함. 
    esc[cur] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    for (int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preorder(R, -1);
    
    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        cout << esc[t] - disc[t] + 1 << "\n";
    }
    

    return 0;
}