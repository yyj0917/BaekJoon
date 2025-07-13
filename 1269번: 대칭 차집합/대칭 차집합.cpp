#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    unordered_map<int, int> um;

    for (int i = 0; i < a + b; i++)
    {
        int val;
        cin >> val;
        um[val]++;
    }

    int result = 0;
    for (auto &m: um)
    {
        if (m.second == 1) result++;
    }
    cout << result << endl;

    return 0;
}