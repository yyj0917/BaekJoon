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
    vector<pair<long long, long long>> meetings(n);
    for (int i = 0; i < n; i++)
    {
        long long start, end;
        cin >> start >> end;
        meetings[i] = {end, start};
    }

    sort(meetings.begin(), meetings.end());

    int cnt = 0;
    long long end_time = 0;

    for (auto& [end, start] : meetings) {
        if (start >= end_time) {
            end_time = end;
            cnt++;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}