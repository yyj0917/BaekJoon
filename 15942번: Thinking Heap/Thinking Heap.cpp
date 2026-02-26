#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1000000;
int n = 0;
int heap[MAX];
void upheap(int id) {
    while (id > 1) {
        if (heap[id / 2] <= heap[id]) break;
        std:swap(heap[id], heap[id / 2]);
        id /= 2;
    }
}
void insert_heap(int value) {
    heap[++n] = value;
    upheap(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int k, p;
    cin >> k >> p;

    vector<bool> inserted(N+1, false);
    vector<int> path;
    int cur = p / 2;
    while (cur > 0)
    {
        path.push_back(cur);
        cur /= 2;
    }
    if (path.size() > k-1) {
        cout << -1; return 0;
    }

    int val = 1;
    for (int i = path.size()-1; i >= 0; i--)
    {
        heap[path[i]] = val;
        inserted[val] = true;
        val++;
    }
    heap[p] = k;
    inserted[k] = true;
    
    queue<int> q;
    int cnt = 0;
    int insert_num = k+1;
    q.push(p);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int x : {cur*2, cur*2+1}) {
            if (x <= N && heap[x] == 0) {
                if (insert_num > N) {
                    cout << -1;
                    return 0;
                }
                heap[x] = insert_num;
                inserted[insert_num] = true;
                insert_num++;
                cnt++;
                q.push(x);
            }
        }
    }
    if (cnt > N - k) {
        cout << -1;
        return 0;
    }
    int unused_num = 1; // 1부터 N까지 차례대로 검사할 포인터

    int num_ptr = 1;
    for (int i = 1; i <= N; i++) {
        if (heap[i] == 0) {
            while (num_ptr <= N && inserted[num_ptr]) {
                num_ptr++;
            }
            if (num_ptr <= N) {
                heap[i] = num_ptr;
                inserted[num_ptr] = true;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << heap[i] << "\n";
    }
    

    return 0;
}