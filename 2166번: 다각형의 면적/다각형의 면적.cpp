#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> coordinate;

long long cross_product(long long x1, long long y1, long long x2, long long y2) {
    return (x1*y2 - x2*y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        coordinate.push_back({x, y});
    }
    
    long long cumulative_sum = 0;
    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;
        cumulative_sum += cross_product(coordinate[i].first, coordinate[i].second, coordinate[j].first, coordinate[j].second);
    }
    cumulative_sum = llabs(cumulative_sum);
    double ans = (double)cumulative_sum / 2.0;
    
    cout << fixed; cout.precision(1);
    cout << ans;
    return 0;
}