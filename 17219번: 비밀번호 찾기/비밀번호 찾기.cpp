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

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> um;

    for (int i = 0; i < n; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        um[str1] = str2;
    }

    for (size_t i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        cout << um[str] << "\n";
    }
    return 0;
}