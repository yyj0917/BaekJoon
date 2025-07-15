#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<long long> line(k);
    
    for (int i = 0; i < k; i++)
    {
        cin >> line[i];
    }
    sort(line.begin(), line.end());
    long long l = 1;
    long long r = line[k - 1];

    long long ans = 0;
    while (l <= r)
    {
        long long cut = (l + r)/2;
        long long cnt = 0;
        for (int i = 0; i < k; i++)
        {
           cnt += line[i]/cut;
        }
        
        if (cnt >= n) {

            l = cut + 1;
            ans = cut;
        } else {
            r = cut - 1;
        }
    }
    
    cout << ans << '\n';

    return 0;
}