#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;

    set<string> s;
    vector<string> v(m);
    vector<string> check_v;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
    {
        if (s.count(v[i])) {
            cnt++;
            check_v.push_back(v[i]);
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < check_v.size(); i++)
    {
       cout << check_v[i] << "\n";
    }
    
    

    return 0;
}