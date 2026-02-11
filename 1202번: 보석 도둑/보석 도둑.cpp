#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

vector<pair<int, int>> jewel;
priority_queue<pair<int, int>> pq_jewel;
vector<int> bag;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        bag.push_back(c);
    }

    // 보석 가치가 더 크고, 무게가 더 나가는 보석이 뒤에 오도록 정렬
    sort(jewel.begin(), jewel.end());
    
    // 최대 무게가 덜 나가는 가방이 먼저 선택하도록
    sort(bag.begin(), bag.end());

    long long ans = 0;
    priority_queue<int> pq;
    int jewel_idx = 0;
    for (int c : bag) {
        
        while (jewel_idx < N && jewel[jewel_idx].first <= c)
        {
            pq.push(jewel[jewel_idx].second);
            jewel_idx++;
        }
        
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    

    return 0;
}