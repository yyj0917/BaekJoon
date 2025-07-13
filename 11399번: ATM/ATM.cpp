#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int sum_min = 0;
    int idx = 0;
    for (int i = n; i > 0; i--)
    {
        sum_min += v[idx] * i;
        idx++;
    }
    
    cout << sum_min << "\n";

    return 0;
}