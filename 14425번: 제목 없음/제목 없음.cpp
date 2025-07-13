#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;

    int n , m;
    cin >> n >> m;

    unordered_set<string> us;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        us.insert(str);
    }

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (us.count(str)) cnt++;
    }
    
    cout << cnt << endl;
    

    return 0;
}