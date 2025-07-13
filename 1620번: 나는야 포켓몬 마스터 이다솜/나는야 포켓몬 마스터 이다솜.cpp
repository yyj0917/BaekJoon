#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isNumber(const string& s) {
    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> v(n+1);
    unordered_map<string, int> map(n);

    for (int i = 1; i < n + 1; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
        map[v[i]] = i;
    }
    
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (isNumber(s)) {
            cout << v[stoi(s)] << "\n";
        } else {
            if (map.count(s)) {
                cout << map[s] << "\n";
            }
            
        }
    }
    

    return 0;
}