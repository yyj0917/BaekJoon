#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    } 
};
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    

    return 0;
}