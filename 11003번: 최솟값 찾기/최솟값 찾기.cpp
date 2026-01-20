#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> V(N);

    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }

    deque<pair<int, int>> dq; // 앞으로 구간의 최솟값이 될 가능성이 있는 원소들 -> {원솟값, index}
    for (int i = 0; i < N; i++)
    {
        // 들어오게 될 원소보다 dq.back에 있는 원소가 더 크면 dq.back 원소는 앞으로 필요가 없어짐 -> 버리기
        while (!dq.empty() && dq.back().first > V[i])
        {
            dq.pop_back();
        }
        dq.push_back({V[i], i});

        // 새로운 원소를 넣은 뒤 최솟값을 판별하기 전 맨 앞에 있는 젤 작은 수와 새로운 원소의 index 차이가 구간 L 내에 있는지 -> 너무 오래된 것이 아닌지 판별 -> 오래됐으면 버리기
        while (!dq.empty() && dq.front().second <= i - L)
        {
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }
    

    return 0;
}