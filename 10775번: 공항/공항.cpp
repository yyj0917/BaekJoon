#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int G, P;

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 0, 1, 2, ..., n으로 채움
    }

    // Find: x의 대장을 찾음 (경로 압축 최적화 포함)
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

    cin >> G >> P;
    UnionFind uf(G+1);
    int max_airplane = 0;
    for (int i = 1; i <= P; i++) {
        int g;
        cin >> g;
        // g번 게이트를 채우고, 여기서 g번은 범위 중 가장 번호가 높은 게이트
        // 다음에 g번 게이트를 방문할 때 g-1번 게이트를 방문하게끔 하려고.
        int dockable_gate = uf.find(g);

        if (dockable_gate == 0) break; // 이미 다 채워졌을 때
        uf.unite(dockable_gate, dockable_gate-1);
        max_airplane++;

    }
    cout << max_airplane << "\n";

    

    return 0;
}