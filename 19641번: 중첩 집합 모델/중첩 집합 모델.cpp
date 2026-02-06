#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;



int N, S;
vector<int> tree[200000];
vector<bool> checked(200000);

int cnt = 0;
vector<int> left_node(100005), right_node(100005);

void solve(int cur, int parent) {
    
    left_node[cur] = ++cnt;
    for (auto nxt : tree[cur])
    {
        if (nxt == parent) continue;
        solve(nxt, cur);
    }

    right_node[cur] = ++cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int V, A;
        cin >> V; // 연결될 정점
        while (true)
        {
            cin >> A;
            if (A == -1) break;
            tree[V].push_back(A);
        }
    }

    // 각 인접 노드 오름차순 진입을 위한 정렬
    for (int i = 1; i <= N; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }

    
    cin >> S;

    solve(S, -1);

    for (int i = 1; i <= N; i++)
    {
        cout << i << " " << left_node[i] << " " << right_node[i] << "\n";
    }
    
    return 0;
}