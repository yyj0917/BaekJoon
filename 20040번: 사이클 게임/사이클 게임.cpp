#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int N, M;

struct UnionFind {
    vector<int> parent;

    // 초기화: 처음에는 자기 자신이 자기의 부모(대장)입니다.
    UnionFind(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 0, 1, 2, ..., n으로 채움
    }

    // Find: x의 대장을 찾음 (경로 압축 최적화 포함)
    int find(int x) {
        if (parent[x] == x) return x;
        // 경로 압축(Path Compression): 찾으러 올라가는 길에 만난 모든 노드를 
        // 직접 대장에게 연결해서 다음 검색 속도를 비약적으로 높입니다.
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

    // 같은 집합에 있는지 확인
    bool isSame(int x, int y) {
        return find(x) == find(y);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    UnionFind uf(N);
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        // 부모가 같을 때 -> 이걸 연결하면 사이클이 처음으로 생기는 것 -> break;
        if (uf.find(a) == uf.find(b)) {
            ans = i+1;
            break;
        } else {
            // 부모가 같지 않다 -> 연결
            uf.unite(a, b);
        }
    }
    
    cout << ans;

    return 0;
}