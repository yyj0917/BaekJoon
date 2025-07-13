#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        string inst;
        cin >> inst;
        if (inst == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (inst == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (inst == "size") {
            cout << q.size() << "\n";
        } else if (inst == "empty") {
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (inst == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }
    

    return 0;
}