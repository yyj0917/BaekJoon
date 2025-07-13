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
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int exception_num = round(n * 0.15);
    double sum = 0;
    for (int i = exception_num; i < n-exception_num; i++)
    {
        sum += v[i];
    }

    double m = n - exception_num * 2;

    cout << round(sum/m) << "\n";
    
    return 0;
}