#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int fruit[n];
    map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        cin >> fruit[i];
    }

    int left = 0, maxLen = 0;

    for (int right = 0; right < n; right++)
    {
        map[fruit[right]]++;

        while (map.size() > 2)
        {
            map[fruit[left]]--;
            if (map[fruit[left]] == 0) map.erase(fruit[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    cout << maxLen << '\n';
    
    return 0;
}