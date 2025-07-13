#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

const unordered_set<int> all_set = [] {
    unordered_set<int> s;
    for (int i = 1; i <= 20; ++i) s.insert(i);
    return s;
}();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_set<int> us;
    while(n--) {
        string inst;
        int x;
        
        cin >> inst;
        if (inst == "all") {
            us = all_set;
        } 
        else if (inst == "empty") {
            us.clear();
        } else {
            cin >> x;
            if (inst == "add") {
                us.insert(x);
            } else if (inst == "remove") {
                us.erase(x);
            } else if (inst == "check") {
                if (us.count(x)) cout << 1 << '\n';
                else cout << 0 << '\n';
            } else if (inst == "toggle") {
                if (us.count(x)) us.erase(x);
                else us.insert(x);
            }
        }
    }

    return 0;
}