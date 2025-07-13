#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> map;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        map[x]++;
        dq.push_back(x);
    }
    
    while (map.size() > 2)
    {
        int f_num = dq.front();
        int b_num = dq.back();

        if (map[f_num] >= map[b_num]) {
            dq.pop_back();
            map[b_num]--;
            if (map[b_num] == 0) map.erase(b_num);
        } else if (map[f_num] < map[b_num]) {
            dq.pop_front();
            map[f_num]--;
            if (map[f_num] == 0) map.erase(f_num);
        } 
    }
    
    int result = 0;
    for (auto x : map) {
        result += x.second;
    }
    cout << result << '\n';
    return 0;
}