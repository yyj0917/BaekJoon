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

    vector<long long> v1; // sort vector
    vector<long long> v2; // origin vector
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v1.push_back(x);
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end()); // 중복제거

    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
    }
    

    
    

    return 0;
}