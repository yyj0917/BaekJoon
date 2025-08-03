#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int n, k;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector<int> dist(222222, 222222);
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty())
    {
       int cur = dq.front();
       dq.pop_front();

       if (cur == k) {
            cout << dist[k] << '\n';
            break;
       }

       int teleport = cur * 2;

       if (teleport <= 200000 && dist[teleport] > dist[cur]) {
            dist[teleport] = dist[cur];
            dq.push_front(teleport);
       }

       int left = cur - 1, right = cur + 1;
       if (left >= 0 && dist[left] > dist[cur] + 1) {
            dist[left] = dist[cur] + 1;
            dq.push_back(left);
       }
       if (right <= 200000 && dist[right] > dist[cur] + 1) {
            dist[right] = dist[cur] + 1;
            dq.push_back(right);
       }
    }

    return 0;
}