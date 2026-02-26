#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int N, M, K;
vector<int> child_candy(30001);

struct UnionFind {
    vector<int> parent;

    UnionFind(int x) {
        parent.resize(x+1);
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    // Union: x가 속한 팀과 y가 속한 팀을 합침
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // 한쪽 대장을 다른 쪽 대장 밑으로 보냅니다.
            parent[rootX] = rootY;
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> child_candy[i];
    }

    vector<int> group_size(N+1, 0);
    vector<int> group_candy(N+1, 0);
    UnionFind uf(N);
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        uf.unite(u, v);
    }
    for (int i = 1; i <= N; i++)
    {
        int root = uf.find(i);
        group_size[root] += 1;
        group_candy[root] += child_candy[i];
    }

    // 배낭 용량은 최대 K - 1
    vector<int> dp(K, 0);
    for (int i = 1; i <= N; i++) {
        int w = group_size[i];
        int v = group_candy[i];

        for (int j = K - 1; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[K-1];
    // int dp[N+1][K]; // K-1까지 가능
    
    // for (int i = 0; i < K; i++) {
    //     dp[0][i] = 0;
    // }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int c = 0; c < K; c++)
    //     {
    //         // 현재 그룹 선택 안 할 때
    //         dp[i][c] = dp[i-1][c];

    //         // 현재 그룹 선택할 때
    //         if (c >= group_size[i]) {
    //             dp[i][c] = max(dp[i][c], dp[i-1][c - group_size[i]] + group_candy[i]);
    //         }
    //     }
    // }
    // cout << dp[N][K-1];
    
    return 0;
}