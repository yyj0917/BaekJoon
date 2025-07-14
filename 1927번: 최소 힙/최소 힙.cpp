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

    int n;
    cin >> n;
    
    multiset<long long> set;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (x == 0) {
            if (set.empty()) cout << 0 << '\n';
            else {
                auto it = set.begin();
                cout << *it << '\n';
                set.erase(set.begin());
            }
        } else {
            set.insert(x);
        }
    }
    

    return 0;
}